#include <functional>
#include <memory>
#include <string>

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

    // 创建一个服务端，服务名为 test_service。----
    service_ = this->create_service<user_interfaces::srv::User>(
      "test_service",
      std::bind(
        &TestNode::service_callback,
        this,
        std::placeholders::_1,
        std::placeholders::_2));
  }

private:
  // 保存订阅者对象，避免离开作用域后订阅失效。
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;

  // 保存服务端对象，避免离开作用域后服务失效。
  rclcpp::Service<user_interfaces::srv::User>::SharedPtr service_;

  // 订阅回调：收到话题消息后被自动调用。
  void callback(const std_msgs::msg::String::ConstSharedPtr msg)
  {
    // 打印收到的消息内容。
    RCLCPP_INFO(this->get_logger(), "get msg: %s", msg->data.c_str());
  }

  // 服务回调：收到请求后被自动调用，并负责填写响应。
  void service_callback(
    const user_interfaces::srv::User::Request::SharedPtr request,
    user_interfaces::srv::User::Response::SharedPtr response)
  {
    // 打印请求内容，方便观察客户端传入了什么参数。
    RCLCPP_INFO(
      this->get_logger(),
      "service request: out1='%s', out2=%u",
      request->out1.c_str(),
      request->out2);

    // 根据请求内容组织响应字符串。
    response->re1 = "received: " + request->out1;

    // 把请求中的数字加 1 后返回，作为示例响应。
    response->re2 = request->out2 + 1;

    // 打印响应内容，确认服务逻辑已经执行。
    RCLCPP_INFO(
      this->get_logger(),
      "service response: re1='%s', re2=%u",
      response->re1.c_str(),
      response->re2);
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
