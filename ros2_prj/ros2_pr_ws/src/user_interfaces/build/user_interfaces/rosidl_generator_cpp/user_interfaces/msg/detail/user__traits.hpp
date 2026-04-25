// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from user_interfaces:msg/User.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "user_interfaces/msg/user.hpp"


#ifndef USER_INTERFACES__MSG__DETAIL__USER__TRAITS_HPP_
#define USER_INTERFACES__MSG__DETAIL__USER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "user_interfaces/msg/detail/user__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'content'
#include "std_msgs/msg/detail/string__traits.hpp"
// Member 'image'
#include "sensor_msgs/msg/detail/image__traits.hpp"

namespace user_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const User & msg,
  std::ostream & out)
{
  out << "{";
  // member: msg_content
  {
    out << "msg_content: ";
    rosidl_generator_traits::value_to_yaml(msg.msg_content, out);
    out << ", ";
  }

  // member: content
  {
    out << "content: ";
    to_flow_style_yaml(msg.content, out);
    out << ", ";
  }

  // member: image
  {
    out << "image: ";
    to_flow_style_yaml(msg.image, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const User & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: msg_content
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "msg_content: ";
    rosidl_generator_traits::value_to_yaml(msg.msg_content, out);
    out << "\n";
  }

  // member: content
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "content:\n";
    to_block_style_yaml(msg.content, out, indentation + 2);
  }

  // member: image
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "image:\n";
    to_block_style_yaml(msg.image, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const User & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace user_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use user_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const user_interfaces::msg::User & msg,
  std::ostream & out, size_t indentation = 0)
{
  user_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use user_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const user_interfaces::msg::User & msg)
{
  return user_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<user_interfaces::msg::User>()
{
  return "user_interfaces::msg::User";
}

template<>
inline const char * name<user_interfaces::msg::User>()
{
  return "user_interfaces/msg/User";
}

template<>
struct has_fixed_size<user_interfaces::msg::User>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<user_interfaces::msg::User>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<user_interfaces::msg::User>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // USER_INTERFACES__MSG__DETAIL__USER__TRAITS_HPP_
