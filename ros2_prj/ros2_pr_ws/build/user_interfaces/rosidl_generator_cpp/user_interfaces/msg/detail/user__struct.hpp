// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from user_interfaces:msg/User.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "user_interfaces/msg/user.hpp"


#ifndef USER_INTERFACES__MSG__DETAIL__USER__STRUCT_HPP_
#define USER_INTERFACES__MSG__DETAIL__USER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'content'
#include "std_msgs/msg/detail/string__struct.hpp"
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__user_interfaces__msg__User __attribute__((deprecated))
#else
# define DEPRECATED__user_interfaces__msg__User __declspec(deprecated)
#endif

namespace user_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct User_
{
  using Type = User_<ContainerAllocator>;

  explicit User_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : content(_init),
    image(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->msg_content = "";
    }
  }

  explicit User_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : msg_content(_alloc),
    content(_alloc, _init),
    image(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->msg_content = "";
    }
  }

  // field types and members
  using _msg_content_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _msg_content_type msg_content;
  using _content_type =
    std_msgs::msg::String_<ContainerAllocator>;
  _content_type content;
  using _image_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _image_type image;

  // setters for named parameter idiom
  Type & set__msg_content(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->msg_content = _arg;
    return *this;
  }
  Type & set__content(
    const std_msgs::msg::String_<ContainerAllocator> & _arg)
  {
    this->content = _arg;
    return *this;
  }
  Type & set__image(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->image = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    user_interfaces::msg::User_<ContainerAllocator> *;
  using ConstRawPtr =
    const user_interfaces::msg::User_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<user_interfaces::msg::User_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<user_interfaces::msg::User_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      user_interfaces::msg::User_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<user_interfaces::msg::User_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      user_interfaces::msg::User_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<user_interfaces::msg::User_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<user_interfaces::msg::User_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<user_interfaces::msg::User_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__user_interfaces__msg__User
    std::shared_ptr<user_interfaces::msg::User_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__user_interfaces__msg__User
    std::shared_ptr<user_interfaces::msg::User_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const User_ & other) const
  {
    if (this->msg_content != other.msg_content) {
      return false;
    }
    if (this->content != other.content) {
      return false;
    }
    if (this->image != other.image) {
      return false;
    }
    return true;
  }
  bool operator!=(const User_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct User_

// alias to use template instance with default allocator
using User =
  user_interfaces::msg::User_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace user_interfaces

#endif  // USER_INTERFACES__MSG__DETAIL__USER__STRUCT_HPP_
