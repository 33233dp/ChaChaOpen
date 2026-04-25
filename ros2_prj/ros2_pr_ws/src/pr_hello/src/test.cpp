#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class testNode : public rclcpp::Node {
	public:
		testNode(std::string node_name) : Node(node_name) {
			RCLCPP_INFO(this->get_logger(), "creat node : %s",node_name.c_str());
			sub_ = this->create_subscription<std_msgs::msg::String>("testTopic", 10, std::bind(&testNode::callback, this, std::placeholders::_1));
		}

	private:
		rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
		
		void callback(std_msgs::msg::String msg) {
			RCLCPP_INFO(this->get_logger(), "get msg : %s",msg.data.c_str());
		}
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<testNode>("test_node");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
