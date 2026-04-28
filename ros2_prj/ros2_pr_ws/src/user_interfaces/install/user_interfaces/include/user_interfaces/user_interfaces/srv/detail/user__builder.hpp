// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from user_interfaces:srv/User.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "user_interfaces/srv/user.hpp"


#ifndef USER_INTERFACES__SRV__DETAIL__USER__BUILDER_HPP_
#define USER_INTERFACES__SRV__DETAIL__USER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "user_interfaces/srv/detail/user__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace user_interfaces
{

namespace srv
{

namespace builder
{

class Init_User_Request_out2
{
public:
  explicit Init_User_Request_out2(::user_interfaces::srv::User_Request & msg)
  : msg_(msg)
  {}
  ::user_interfaces::srv::User_Request out2(::user_interfaces::srv::User_Request::_out2_type arg)
  {
    msg_.out2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::user_interfaces::srv::User_Request msg_;
};

class Init_User_Request_out1
{
public:
  Init_User_Request_out1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_User_Request_out2 out1(::user_interfaces::srv::User_Request::_out1_type arg)
  {
    msg_.out1 = std::move(arg);
    return Init_User_Request_out2(msg_);
  }

private:
  ::user_interfaces::srv::User_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::user_interfaces::srv::User_Request>()
{
  return user_interfaces::srv::builder::Init_User_Request_out1();
}

}  // namespace user_interfaces


namespace user_interfaces
{

namespace srv
{

namespace builder
{

class Init_User_Response_re2
{
public:
  explicit Init_User_Response_re2(::user_interfaces::srv::User_Response & msg)
  : msg_(msg)
  {}
  ::user_interfaces::srv::User_Response re2(::user_interfaces::srv::User_Response::_re2_type arg)
  {
    msg_.re2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::user_interfaces::srv::User_Response msg_;
};

class Init_User_Response_re1
{
public:
  Init_User_Response_re1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_User_Response_re2 re1(::user_interfaces::srv::User_Response::_re1_type arg)
  {
    msg_.re1 = std::move(arg);
    return Init_User_Response_re2(msg_);
  }

private:
  ::user_interfaces::srv::User_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::user_interfaces::srv::User_Response>()
{
  return user_interfaces::srv::builder::Init_User_Response_re1();
}

}  // namespace user_interfaces


namespace user_interfaces
{

namespace srv
{

namespace builder
{

class Init_User_Event_response
{
public:
  explicit Init_User_Event_response(::user_interfaces::srv::User_Event & msg)
  : msg_(msg)
  {}
  ::user_interfaces::srv::User_Event response(::user_interfaces::srv::User_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::user_interfaces::srv::User_Event msg_;
};

class Init_User_Event_request
{
public:
  explicit Init_User_Event_request(::user_interfaces::srv::User_Event & msg)
  : msg_(msg)
  {}
  Init_User_Event_response request(::user_interfaces::srv::User_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_User_Event_response(msg_);
  }

private:
  ::user_interfaces::srv::User_Event msg_;
};

class Init_User_Event_info
{
public:
  Init_User_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_User_Event_request info(::user_interfaces::srv::User_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_User_Event_request(msg_);
  }

private:
  ::user_interfaces::srv::User_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::user_interfaces::srv::User_Event>()
{
  return user_interfaces::srv::builder::Init_User_Event_info();
}

}  // namespace user_interfaces

#endif  // USER_INTERFACES__SRV__DETAIL__USER__BUILDER_HPP_
