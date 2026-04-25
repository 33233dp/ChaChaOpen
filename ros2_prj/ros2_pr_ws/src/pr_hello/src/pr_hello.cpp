#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/u_int32.hpp"

class hello : public rclcpp::Node

{

  public:

    hello(std::string node_name) : Node(node_name) {
    
      RCLCPP_INFO(this->get_logger(), "created node: %s\n", node_name.c_str());
      
      sub_ = this->create_subscription<std_msgs::msg::String>("hello_topic", 10, std::bind(&hello::callback, this, std::placeholders::_1));
      pub_ = this->create_publisher<std_msgs::msg::String>("hello_topic", 10);
    }

  private:

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
    
    void callback(std_msgs::msg::String msg) {
      RCLCPP_INFO(this->get_logger(), "get msg: %s\n", msg.data.c_str());
      std_msgs::msg::String pub_msg;
      pub_msg.data = "hello world";
      pub_->publish(pub_msg);
    }

};


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<hello>("hello_node");
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
  
}