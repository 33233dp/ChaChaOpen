https://github.com/petercorke/robotics-toolbox-matlab
# Robotics Toolbox for MATLAB® release 10
---
For support please use the [Google group forum](http://groups.google.com/group/robotics-tool-box?hl=en) rather than GitHub issues. There are more people participating and you'll likely get a quicker response. Checkout the [FAQ](https://petercorke.com/toolboxes/faq) before you post a question, it covers common problems that arise with incorrect MATLAB paths.
- - -
# 简介
- - -
This toolbox brings robotics specific functionality to MATLAB, exploiting the native capabilities of MATLAB (linear algebra, portability, graphics). 
该工具箱利用 MATLAB 的原生能力（如线性代数、可移植性和图形处理），为 MATLAB 提供了面向机器人学的专用功能。

The Toolbox uses a very general method of representing the kinematics and dynamics of serial-link manipulators as MATLAB® objects – robot objects can be created by the user for any serial-link manipulator and a number of examples are provided for well known robots from Kinova, Universal Robotics, Rethink as well as classical robots such as the Puma 560 and the Stanford arm.
机器人学工具箱采用一种通用的方法，将串联连杆机械臂的运动学和动力学表示为 MATLAB® 对象——用户可以为任意串联连杆机械臂创建机器人对象。同时，工具箱还提供了多个知名机器人的示例，例如 Kinova、Universal Robotics、Rethink 的机器人，以及经典机器人如 Puma 560 和 Stanford 机械臂。

The toolbox also supports mobile robots with functions for robot motion models (unicycle, bicycle), path planning algorithms (bug, distance transform, D*, PRM), kinodynamic planning (lattice, RRT), localization (EKF, particle filter), map building (EKF) and simultaneous localization and mapping (EKF), and a Simulink model a of non-holonomic vehicle. The Toolbox also including a detailed Simulink model for a quadrotor flying robot.
这个工具箱还支持移动机器人，提供多种功能，包括机器人运动模型（单轮模型，自行车模型），路径规划算法（Bug算法，距离变换，D*，PRM），运动学与运动力学约束规划（格点法，PRT），定位方法（扩展卡尔曼滤波 EKF, 粒子滤波），地图构建（EKF）以及同步定位与建图（SLAM，基于EKF），并提供了一个非完整约束车辆的 Simulink 模型。此外，这个工具箱包含详细的四旋翼飞行机器人的Simulink仿真模型。

Advantages of the Toolbox are that:
- the code is mature and provides a point of comparison for other implementations of the same algorithms;
- the routines are generally written in a straightforward manner which allows for easy understanding, perhaps at the expense of computational efficiency. If you feel strongly about computational efficiency then you can always rewrite the function to be more efficient, compile the M-file using the MATLAB compiler, or create a MEX version;
- since source code is available there is a benefit for understanding and teaching.
**该工具箱的优势包括：**
- 代码较为成熟，并且为相同算法的其他实现提供了良好的对比参考；
- 大多数例程采用直观、易读的方式编写，便于理解，但这在一定程度上可能以牺牲计算效率为代价。如果你对计算效率有较高要求，可以自行对函数进行优化重写，或使用 MATLAB 编译器对 M 文件进行编译，亦可创建对应的 MEX 版本；
- 由于源码开放，这对于学习和教学具有重要价值。