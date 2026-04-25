// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from user_interfaces:msg/User.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "user_interfaces/msg/user.hpp"


#ifndef USER_INTERFACES__MSG__DETAIL__USER__BUILDER_HPP_
#define USER_INTERFACES__MSG__DETAIL__USER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "user_interfaces/msg/detail/user__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace user_interfaces
{

namespace msg
{

namespace builder
{

class Init_User_image
{
public:
  explicit Init_User_image(::user_interfaces::msg::User & msg)
  : msg_(msg)
  {}
  ::user_interfaces::msg::User image(::user_interfaces::msg::User::_image_type arg)
  {
    msg_.image = std::move(arg);
    return std::move(msg_);
  }

private:
  ::user_interfaces::msg::User msg_;
};

class Init_User_content
{
public:
  explicit Init_User_content(::user_interfaces::msg::User & msg)
  : msg_(msg)
  {}
  Init_User_image content(::user_interfaces::msg::User::_content_type arg)
  {
    msg_.content = std::move(arg);
    return Init_User_image(msg_);
  }

private:
  ::user_interfaces::msg::User msg_;
};

class Init_User_msg_content
{
public:
  Init_User_msg_content()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_User_content msg_content(::user_interfaces::msg::User::_msg_content_type arg)
  {
    msg_.msg_content = std::move(arg);
    return Init_User_content(msg_);
  }

private:
  ::user_interfaces::msg::User msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::user_interfaces::msg::User>()
{
  return user_interfaces::msg::builder::Init_User_msg_content();
}

}  // namespace user_interfaces

#endif  // USER_INTERFACES__MSG__DETAIL__USER__BUILDER_HPP_
