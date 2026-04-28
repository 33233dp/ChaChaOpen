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
 	  // 创建客户端
	  client_ = this->create_client<user_interfaces::srv::User>("test_service");
	  // 创建服务端
	  service_ = this->create_service<user_interfaces::srv::User>("test_service", std::bind(&TestNode::service_callback, this, std::placeholders::_1, std::placeholders::_2));
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
    auto request = std::make_shared<user_interfaces::srv::User::Request>();
    // 编辑消息内容
    request->req1 = "get msg" + msg->data;
    request->req2 = 520;
    // 异步请求
    client_->async_send_request(request, std::bind(&TestNode::client_request_callback, this, std::placeholders::_1));
  }

  void client_request_callback(rclcpp::Client<user_interfaces::srv::User>::SharedFuture future) {
 	auto response = future.get();
	RCLCPP_INFO(this->get_logger(), "get reply>> resp1 = '%s',resp2 = %u",response->resp1.c_str(), response->resp2);
  }
  
  //服务回调，收到请求后自动调用
  void service_callback(const user_interfaces::srv::User::Request::SharedPtr request, user_interfaces::srv::User::Response::SharedPtr response) {
  	//打印信息
	  RCLCPP_INFO(this->get_logger(), "get request>> req1='%s',req2=%u",request->req1.c_str(), request->req2);
	//拼接响应字符串
	response->resp1 = "test_service response >> request received which is" + request->req1;
	response->resp2 =  request->req2;
	//打印响应内容
	RCLCPP_INFO(this->get_logger(), "%s  second response:%u",response->resp1.c_str(), response->resp2);
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
