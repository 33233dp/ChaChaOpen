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

class Init_User_user_msg
{
public:
  Init_User_user_msg()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::user_interfaces::msg::User user_msg(::user_interfaces::msg::User::_user_msg_type arg)
  {
    msg_.user_msg = std::move(arg);
    return std::move(msg_);
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
  return user_interfaces::msg::builder::Init_User_user_msg();
}

}  // namespace user_interfaces

#endif  // USER_INTERFACES__MSG__DETAIL__USER__BUILDER_HPP_
