cmake_minimum_required(VERSION 3.8)
project(user_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 添加sensor_msgs和std_msgs的功能包

find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
# 添加自定义接口的依赖

find_package(rosidl_default_generators REQUIRED)

#添加消息文件和依赖
rosidl_generate_interfaces(${PROJECT_NAME}
	"msg/User.msg" #要和msg文件夹下的.msg文件名一致
	DEPENDENCIES std_msgs
)

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

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
