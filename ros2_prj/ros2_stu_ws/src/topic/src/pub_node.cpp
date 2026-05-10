#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include <chrono>
#include <functional>
#include <memory>
#include <string>

using namespace std::chrono_literals;

class PubNode : public rclcpp::Node {
public:
  explicit PubNode(const std::string & node_name)
  : Node(node_name), count_(0)
  {
    RCLCPP_INFO(this->get_logger(), "create node: %s", node_name.c_str());
    pub_ = this->create_publisher<std_msgs::msg::String>("topic_msg", 10);
    timer_ = this->create_wall_timer(
      1s, std::bind(&PubNode::on_timer, this));
  }

private:
  void on_timer()
  {
    std_msgs::msg::String msg;
    msg.data = "hello ros2 topic msg #" + std::to_string(count_++);
    RCLCPP_INFO(this->get_logger(), "pub msg: %s", msg.data.c_str());
    pub_->publish(msg);
  }

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
  size_t count_;
};

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<PubNode>("pub_node");
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
