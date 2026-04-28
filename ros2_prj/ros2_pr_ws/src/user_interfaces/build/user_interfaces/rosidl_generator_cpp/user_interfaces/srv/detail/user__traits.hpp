// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from user_interfaces:srv/User.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "user_interfaces/srv/user.hpp"


#ifndef USER_INTERFACES__SRV__DETAIL__USER__TRAITS_HPP_
#define USER_INTERFACES__SRV__DETAIL__USER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "user_interfaces/srv/detail/user__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace user_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const User_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: out1
  {
    out << "out1: ";
    rosidl_generator_traits::value_to_yaml(msg.out1, out);
    out << ", ";
  }

  // member: out2
  {
    out << "out2: ";
    rosidl_generator_traits::value_to_yaml(msg.out2, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const User_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: out1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "out1: ";
    rosidl_generator_traits::value_to_yaml(msg.out1, out);
    out << "\n";
  }

  // member: out2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "out2: ";
    rosidl_generator_traits::value_to_yaml(msg.out2, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const User_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace user_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use user_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const user_interfaces::srv::User_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  user_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use user_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const user_interfaces::srv::User_Request & msg)
{
  return user_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<user_interfaces::srv::User_Request>()
{
  return "user_interfaces::srv::User_Request";
}

template<>
inline const char * name<user_interfaces::srv::User_Request>()
{
  return "user_interfaces/srv/User_Request";
}

template<>
struct has_fixed_size<user_interfaces::srv::User_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<user_interfaces::srv::User_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<user_interfaces::srv::User_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace user_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const User_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: re1
  {
    out << "re1: ";
    rosidl_generator_traits::value_to_yaml(msg.re1, out);
    out << ", ";
  }

  // member: re2
  {
    out << "re2: ";
    rosidl_generator_traits::value_to_yaml(msg.re2, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const User_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: re1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "re1: ";
    rosidl_generator_traits::value_to_yaml(msg.re1, out);
    out << "\n";
  }

  // member: re2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "re2: ";
    rosidl_generator_traits::value_to_yaml(msg.re2, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const User_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace user_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use user_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const user_interfaces::srv::User_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  user_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use user_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const user_interfaces::srv::User_Response & msg)
{
  return user_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<user_interfaces::srv::User_Response>()
{
  return "user_interfaces::srv::User_Response";
}

template<>
inline const char * name<user_interfaces::srv::User_Response>()
{
  return "user_interfaces/srv/User_Response";
}

template<>
struct has_fixed_size<user_interfaces::srv::User_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<user_interfaces::srv::User_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<user_interfaces::srv::User_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace user_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const User_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const User_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const User_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace user_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use user_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const user_interfaces::srv::User_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  user_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use user_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const user_interfaces::srv::User_Event & msg)
{
  return user_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<user_interfaces::srv::User_Event>()
{
  return "user_interfaces::srv::User_Event";
}

template<>
inline const char * name<user_interfaces::srv::User_Event>()
{
  return "user_interfaces/srv/User_Event";
}

template<>
struct has_fixed_size<user_interfaces::srv::User_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<user_interfaces::srv::User_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<user_interfaces::srv::User_Request>::value && has_bounded_size<user_interfaces::srv::User_Response>::value> {};

template<>
struct is_message<user_interfaces::srv::User_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<user_interfaces::srv::User>()
{
  return "user_interfaces::srv::User";
}

template<>
inline const char * name<user_interfaces::srv::User>()
{
  return "user_interfaces/srv/User";
}

template<>
struct has_fixed_size<user_interfaces::srv::User>
  : std::integral_constant<
    bool,
    has_fixed_size<user_interfaces::srv::User_Request>::value &&
    has_fixed_size<user_interfaces::srv::User_Response>::value
  >
{
};

template<>
struct has_bounded_size<user_interfaces::srv::User>
  : std::integral_constant<
    bool,
    has_bounded_size<user_interfaces::srv::User_Request>::value &&
    has_bounded_size<user_interfaces::srv::User_Response>::value
  >
{
};

template<>
struct is_service<user_interfaces::srv::User>
  : std::true_type
{
};

template<>
struct is_service_request<user_interfaces::srv::User_Request>
  : std::true_type
{
};

template<>
struct is_service_response<user_interfaces::srv::User_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // USER_INTERFACES__SRV__DETAIL__USER__TRAITS_HPP_
