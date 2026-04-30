cmake_minimum_required(VERSION 3.8)
project(topic)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

##### 用户添加 # 新增.cpp文件后，需要在CMakeLists.txt中添加相关代码

# 新增.cpp文件后，需要通过find_package找到相关的依赖库
find_package(std_msgs REQUIRED)
# 新增.cpp文件后，从你的.cpp文件声明一个会生成可执行文件的目标。左边：目标名称，右边：目标源文件
add_executable(sub_node src/sub.cpp)  
add_executable(pub_node src/pub.cpp)
# 新增.cpp文件后需要声明**目标**要依赖的库
ament_target_dependencies(sub_node rclcpp std_msgs)
ament_target_dependencies(pub_node rclcpp std_msgs)
# 新增文件后要安装文件
install(
	TARGETS
	sub_node
	pub_node
	DESTINATION
	lib/${PROJECT_NAME}
	)

###

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
