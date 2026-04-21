``` cpp
class hello : public rclcpp::Node {
	public:
		hello() : Node(std::String node) {
			sub_ = rclcpp::creat_subscription<std_msgs::msgs::String>("start",10,std::bind(&hello::callback,this,std::placehoder_1));
		}
	private:
		rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_
		
		void callback(std_msg::msg::String msg) {
			RCLCPP_INFO(this->get_logger(),"node occurde : %s",msg.data.c_str());
		}
};
```