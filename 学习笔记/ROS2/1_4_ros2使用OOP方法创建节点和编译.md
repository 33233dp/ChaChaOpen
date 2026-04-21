1.编写代码
``` cpp

#include "rclcpp/rclcpp.hpp"

/*
    创建一个类节点，名字叫做SingleDogNode,继承自Node.
*/
class SingleDogNode : public rclcpp::Node
{

public:
    // 构造函数,有一个参数为节点名称
    SingleDogNode(std::string name) : Node(name)
    {
        // 打印一句自我介绍
        RCLCPP_INFO(this->get_logger(), "大家好，我是单身狗%s.",name.c_str());
    }

private:
   
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    /*产生一个Wang2的节点*/
    auto node = std::make_shared<SingleDogNode>("wang2");
    /* 运行节点，并检测退出信号*/
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
```
2.添加到CMakeLists
``` txt
add_executable(wang2_node src/wang2.cpp) 
ament_target_dependencies(wang2_node rclcpp)

install(TARGETS 
	wang2_node 
	DESTINATION 
	lib/${PROJECT_NAME} )
```
3.进工作空间编译和运行
```shell
colcon build
source install/setup.bash
ros2 run village_wang wang_node
```
![[Pasted image 20260416165641.png]]

``` shell
ros2 node list
```
![[Pasted image 20260416165713.png]]
