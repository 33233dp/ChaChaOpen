#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class subNode : public rclcpp::Node {
	public:
		subNode(std::string node_name) : Node(node_name) {
			RCLCPP_INFO(this->get_logger(), "sub_node created!");
			sub_ = this->create_subscription<std_msgs::msg::String>("sub_node", 10, std::bind(&subNode::callback, this, std::placeholders::_1));
		}
	private:
		rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;

		void callback(std_msgs::msg::String msg) {
			RCLCPP_INFO(this->get_logger(), "get topic: msg='%s'", msg.data.c_str());
		}
};

int main(int argc, char **argv) {
	rclcpp::init(argc, argv);
	auto node = std::make_shared<subNode>("sub_node");
	rclcpp::spin(node);
	rclcpp::shutdown();
	return 0;
}

