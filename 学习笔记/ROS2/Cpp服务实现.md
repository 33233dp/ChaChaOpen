### 步骤
1. 导入服务接口
2. 创建服务回调函数
3. 声明并创建服务端
4. 编写服务函数逻辑处理请求
### 添加服务接口与依赖
- - -
**第一步修改`package.xml`**
```
  <depend>user_interfaces</depend>
```
**第二步修改和`CMakeLists.txt`**
```
find_package(village_interfaces REQUIRED)
```
```
ament_target_dependencies(wang2_node 
  rclcpp 
  village_interfaces
)
```
**添加服务接口**
```
#include "user_interfaces/srv/sell_novel.hpp"
```
**声明回调函数**
```
// 声明一个回调函数，当收到买书请求时调用该函数，用于处理数据
void sell_book_callback(const village_interfaces::srv::SellNovel::Request::SharedPtr request,
        const village_interfaces::srv::SellNovel::Response::SharedPtr response)
{
}
```
**创建队列**
```
 #include <queue>
//创建一个小说章节队列
std::queue<std::string>  novels_queue;
```
**[[死锁]]**
**[[多线程]]**

**cpp服务**
```cpp
#include <functional>
#include <memory>
#include <string>
#include <chrono>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "user_interfaces/srv/user.hpp"

// 这个节点同时演示订阅和服务两种 ROS 2 功能。
class TestNode : public rclcpp::Node {
public:
  // 构造函数负责完成节点初始化和资源创建。
  explicit TestNode(const std::string & node_name)
  : Node(node_name)
  {
    // 打印节点创建日志，方便确认节点已经启动。
    RCLCPP_INFO(this->get_logger(), "create node: %s", node_name.c_str());

    // 创建一个订阅者，监听 testTopic 话题。
    sub_ = this->create_subscription<std_msgs::msg::String>(
      "testTopic",
      10,
      std::bind(&TestNode::callback, this, std::placeholders::_1));
    //创建一个客户端，然后在回调函数里面请求 test_service
    client_ = this->create_client<user_interfaces::srv::User>("test_service");  
    //创建一个服务端，服务名为 test_service
    service_ = this->create_service<user_interfaces::srv::User>(
   	 "test_service",
	 std::bind(
	 	&TestNode::service_callback,
		this,
		std::placeholders::_1,
		std::placeholders::_2
  	 )
    ); 
  }

private:
  // 订阅者对象变量
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;

  // 客户端对象变量
  rclcpp::Client<user_interfaces::srv::User>::SharedPtr client_;
  
  // 服务对象变量
  rclcpp::Service<user_interfaces::srv::User>::SharedPtr service_;

  // 订阅回调：收到话题消息后被自动调用。
  void callback(const std_msgs::msg::String::ConstSharedPtr msg)
  {
    // 打印收到的消息内容。
    RCLCPP_INFO(this->get_logger(), "get msg: %s", msg->data.c_str());
    // 服务请求
  	//创建服务请求对象（注意不要和客户端混淆）
	  auto request = std::make_shared<user_interfaces::srv::User::Request>();
    //将订阅到的消息内容作为请求参数发送给服务端
	  request->req1 = msg->data;
	  request->req2 = 3;
	  //异步发送服务请求。请求发出去之后，不用等结果，程序可以继续往下执行。
    //服务端返回response->客户端收到response->response写入future->future就绪->回调函数被调用
    //异步发送服务请求 = 发完请求就走人，不等结果，结果回来再通知（用回调）
    //匿名函数作为回调函数，服务响应到达时被自动调用
    //[this]是捕获列表，表示回调函数可以访问当前对象的成员变量和成员函数
    //[this](rclcpp::Client<user_interfaces::srv::User>::SharedFuture future)这是一个 Lambda表达式的“函数头”，而不是函数名。 
    //它定义了一个匿名函数，接受一个参数 future，类型为 rclcpp::Client<user_interfaces::srv::User>::SharedFuture。这个参数表示服务请求的结果将通过这个 future 对象传递回来。
	  //future是一个智能指针，封装了服务请求的结果。当服务响应到达时，future对象会被设置为就绪状态，可以通过调用 future.get() 来获取服务响应的内容。
    client_->async_send_request(request,[this](rclcpp::Client<user_interfaces::srv::User>::SharedFuture future) {
    //从future中取出服务响应
    auto response = future.get();
    //打印服务端请求结果
    RCLCPP_INFO(this->get_logger(),"service reply>> resp1 = '%s' resp2 = %u",response->resp1.c_str(),response->resp2);
    });

  }
  
  //服务回调，收到请求后自动调用
  //   request：客户端发来的请求（只读）
  // response：你要填写的回复（写进去）
  //服务端回调函数传入 response，是让你直接在里面填写响应数据，而不是通过 return 返回，这样更高效、也更符合 ROS2 的异步架构设计。
  void service_callback(const user_interfaces::srv::User::Request::SharedPtr request, user_interfaces::srv::User::Response::SharedPtr response) {
	//打印请求内容
	RCLCPP_INFO(this->get_logger(),"service request->req1:'%s',req2:'%u'",request->req1.c_str(),request->req2);
	//组织响应字符串
	response->resp1 = "received: " + request->req1;
	response->resp2 = request->req2 + 1;
	//打印相应内容
	RCLCPP_INFO(this->get_logger(),"service response>> resp1 = '%s', resp2 = '%u'",response->resp1.c_str(),response->resp2);
  }
};

// 程序入口，负责初始化 ROS 2、启动节点、最后释放资源。
int main(int argc, char * argv[])
{
  // 初始化 ROS 2 通信环境。
  rclcpp::init(argc, argv);

  // 创建节点对象。
  auto node = std::make_shared<TestNode>("test_node");

  // 进入事件循环，等待订阅消息和服务请求。
  rclcpp::spin(node);

  // 关闭 ROS 2 通信环境。
  rclcpp::shutdown();

  return 0;
}


```
[[cpp创建服务总结]]
