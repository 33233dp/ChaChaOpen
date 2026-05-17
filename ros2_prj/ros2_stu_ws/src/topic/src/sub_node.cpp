#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

// 创建类subNode，继承自rclcpp::Node
// 继承的作用：获得rclcpp::Node的所有功能和属性
class subNode : public rclcpp::Node {
	public:
		// 创建构造函数，参数为节点名称
		// 初始化列表：调用父类构造函数，传入节点名称
		// Node(node_name)的作用：创建一个ROS2节点，并将节点名称设置为node_name
		subNode(std::string node_name) : Node(node_name) {
			// 输出日志，显示创建的节点名称
			// node_name是传入的参数，它的类型是std::string，而std::string是C++中的字符串类
			// c_str()将其转换为C风格字符串，以便在日志中显示
			RCLCPP_INFO(this->get_logger(),"create node : %s",node_name.c_str());
			// 创建订阅者，订阅名为"topic_msg"的主题，队列长度为10
			// std::bind(&subNode::callback, this, std::placeholders::_1)的作用：
			// 将成员函数callback绑定为回调函数，当接收到消息时调用
			// 其中placeholders::_1表示回调函数的第一个参数，即接收到的消息。它本身是一个占位符。
			sub_ = this->create_subscription<std_msgs::msg::String>("topic_msg", 10, std::bind(&subNode::callback, this, std::placeholders::_1));
		}
	private:
		// 创建一个类型为rclcpp::Subscription<std_msgs::msg::String>::SharedPtr的成员变量sub_
		// 该类型表示一个智能指针，指向一个订阅者对象
		rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
		// 定义回调函数callback，参数为std_msgs::msg::String类型的消息
		void callback(std_msgs::msg::String msg) {
			RCLCPP_INFO(this->get_logger(), "sub get msg : %s", msg.data.c_str());
		}
};

int main(int argc, char* argv[]) {
	// 初始化ROS2，传入命令行参数
	rclcpp::init(argc, argv); 
	// 创建一个智能指针，指向一个subNode对象，节点名称为"sub_node"
	auto node = std::make_shared<subNode>("sub_node");
	// 进入循环，等待接收消息并调用回调函数
	rclcpp::spin(node);
	// 关闭ROS2
	rclcpp::shutdown();
	return 0;
}

