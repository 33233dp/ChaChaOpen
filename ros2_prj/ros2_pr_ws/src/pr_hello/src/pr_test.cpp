#include <chrono>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class prTestNode : public rclcpp::Node {
	public:
		prTestNode(std::string node_name) : Node(node_name), count_(0) {
			RCLCPP_INFO(this->get_logger(),"create pr test node :%s",node_name.c_str());
			pub_ = this->create_publisher<std_msgs::msg::String>("testTopic",10);
			timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&prTestNode::timer_callback, this));
		}
	private:
		rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
		rclcpp::TimerBase::SharedPtr timer_;
		size_t count_;

		void timer_callback() {
			std_msgs::msg::String msg;
			msg.data = "hello from pr test node #" + std::to_string(count_++);
			RCLCPP_INFO(this->get_logger(),"publish msg : %s", msg.data.c_str());
			pub_->publish(msg);
		}
};


int main(int argc, char * argv[])
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<prTestNode>("pr_test_node");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
