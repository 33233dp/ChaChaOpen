#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class pubNode : public rclcpp::Node {
	public:
		pubNode(const std::string & node_name) : Node(node_name), count_(0) {
			pub_ = this->create_publisher<std_msgs::msg::String>("sub_node", 10);
			timer_ = this->create_wall_timer(1s, std::bind(&pubNode::publish_msg, this));
		}

	private:
		rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
		rclcpp::TimerBase::SharedPtr timer_;
		size_t count_;

		void publish_msg() {
			auto msg = std_msgs::msg::String();
			msg.data = "hello, world " + std::to_string(count_++);
			RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", msg.data.c_str());
			pub_->publish(msg);
		}
};

int main(int argc, char **argv) {
	rclcpp::init(argc, argv);
	auto node = std::make_shared<pubNode>("pub_node");
	RCLCPP_INFO(node->get_logger(), "pub_node created!");
	rclcpp::spin(node);
	rclcpp::shutdown();
	return 0;
}
