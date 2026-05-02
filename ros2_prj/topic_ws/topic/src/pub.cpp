#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class pubNode : public rclcpp::Node {
	public:
		pubNode(std::string node_name) : Node(node_name) {
			pub_ = this->create_publisher<std_msgs::msg::String>("topicNode", 10);
		}
	private:
		rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
		
};

int main(int argc, char** argv) {
	rclcpp::init(argc, argv);
	auto node = std::make_shared<pubNode>("pub_node");
	rclcpp::spin(node);
	RCLCPP_INFO(node->get_logger(), "pub node created!");
	rclcpp::shutdown();
	return 0;
}
