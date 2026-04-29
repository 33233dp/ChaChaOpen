1.编写代码
``` cpp

  

#include "rclcpp/rclcpp.hpp" // ROS 2 C++ 客户端库的主头文件，包含了创建节点、订阅者、发布者等功能。

#include "std_msgs/msg/string.hpp" // ROS 2 标准消息类型库中的 String 消息类型头文件。

#include "user_interfaces/srv/user.hpp" // 用户自定义服务类型的头文件，包含了服务请求和响应的定义。

// 订阅者节点类，继承自 rclcpp::Node。

class testNode :public rclcpp::Node {

	public:
	
	// 构造函数，负责节点的初始化和订阅者的创建。
	
		testNode(std::string node_name) : Node(node_name) {
		
			RCLCPP_INFO(this->get_logger(), "testNode has been created.");
			
			// 创建一个订阅者，订阅 "testTopic" 话题，消息类型为 std_msgs::msg::String，队列大小为 10。
			
			sub_ = this->create_subscription<std_msgs::msg::String>("testTopic", 10, std::bind(&testNode::sub_callback, this, std::placeholders::_1));
		
	}
	
	private:
	
	// 订阅者对象，用于接收消息。
	
		rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
	
	// 订阅回调函数，当接收到消息时被调用，打印消息内容。
	
		void sub_callback(std_msgs::msg::String msg) {
	
			RCLCPP_INFO(this->get_logger(), "get testTopic: %s", msg.data.c_str());
	
	}

};

  

// 程序入口，负责初始化 ROS 2、启动节点、最后释放资源。

int main(int argc, char * argv[])

{

	// 初始化 ROS 2 通信环境。
	
	rclcpp::init(argc, argv);
	
	  
	
	// 创建节点对象。
	
	auto node = std::make_shared<testNode>("test_node");
	
	  
	
	// 进入事件循环，等待订阅消息和服务请求。
	
	rclcpp::spin(node);
	
	  
	
	// 关闭 ROS 2 通信环境。
	
	rclcpp::shutdown();
	
	  
	
	return 0;

}
```
2.添加到CMakeLists
``` txt
add_executable(wang2_node src/wang2.cpp) 
ament_target_dependencies(wang2_node rclcpp)

install(TARGETS 
	wang2_node 
	DESTINATION 
	lib/${PROJECT_NAME} )
```
3.进工作空间编译和运行
```shell
colcon build
source install/setup.bash
ros2 run village_wang wang_node
```
![[Pasted image 20260416165641.png]]

``` shell
ros2 node list
```
![[Pasted image 20260416165713.png]]
