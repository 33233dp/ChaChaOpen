>POP面向过程变成
>OOP面向对象编程

**1.创建工作空间**
```
mkdir -p town_ws/src
cd town_ws/src
```
**2.在src下面创建功能包**
```
ros2 pkg create village_li --build-type ament_cmake --dependencies rclcpp
```
- pkg create 是创建包的意思
- --build-type 用来指定该包的编译类型，一共有三个可选项`ament_python`、`ament_cmake`、`cmake`
- --dependencies 指的是这个功能包的依赖
-
最后得到文件结构
![[Pasted image 20260416162041.png]]
**3.在功能包的src文件夹下创建节点**
``` shell
cd src && nano wang2.cpp
```
**4.编写代码**
``` cpp
#include "rclcpp/rclcpp.hpp"


int main(int argc, char **argv)
{
	/* 初始化rclcpp */
    rclcpp::init(argc, argv);
    /*产生一个Wang2的节点*/
    auto node = std::make_shared<rclcpp::Node>("wang2");
    // 打印一句自我介绍
    RCLCPP_INFO(node->get_logger(), "大家好，我是单身狗wang2.");
    /* 运行节点，并检测退出信号*/
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
```
**5.添加到CMakeLists**
	在CMakeLists最后一行添加。
``` txt
# 从用户的cpp文件构建一个会生成可执行文件的目标。左边：目标名称，右边：目标源文件
add_executable(wang2_node src/wang2.cpp) 
# 
ament_target_dependencies(wang2_node rclcpp)
```
	需要手动将编译好的文件安装到`install/village_wang/lib/village_wang`下在CMakeLists
	因此最后一行添加。
``` txt
install(TARGETS 
	wang2_node 
	DESTINATION 
	lib/${PROJECT_NAME} )
```

**6.编译节点**
**进入工作空间**文件夹并执行
```shell
colcon build
```
source环境
```shell
source install/setup.bash
```
运行节点
```shell
ros2 run village_wang wang2_node
```
![[Pasted image 20260416163726.png]]
**7.测试**
``` shell
ros2 node list
```
![[Pasted image 20260416163816.png]]
