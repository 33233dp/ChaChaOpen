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

class Init_User_Request_req2
{
public:
  explicit Init_User_Request_req2(::user_interfaces::srv::User_Request & msg)
  : msg_(msg)
  {}
  ::user_interfaces::srv::User_Request req2(::user_interfaces::srv::User_Request::_req2_type arg)
  {
    msg_.req2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::user_interfaces::srv::User_Request msg_;
};

class Init_User_Request_req1
{
public:
  Init_User_Request_req1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_User_Request_req2 req1(::user_interfaces::srv::User_Request::_req1_type arg)
  {
    msg_.req1 = std::move(arg);
    return Init_User_Request_req2(msg_);
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
  return user_interfaces::srv::builder::Init_User_Request_req1();
}

}  // namespace user_interfaces


namespace user_interfaces
{

namespace srv
{

namespace builder
{

class Init_User_Response_resp2
{
public:
  explicit Init_User_Response_resp2(::user_interfaces::srv::User_Response & msg)
  : msg_(msg)
  {}
  ::user_interfaces::srv::User_Response resp2(::user_interfaces::srv::User_Response::_resp2_type arg)
  {
    msg_.resp2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::user_interfaces::srv::User_Response msg_;
};

class Init_User_Response_resp1
{
public:
  Init_User_Response_resp1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_User_Response_resp2 resp1(::user_interfaces::srv::User_Response::_resp1_type arg)
  {
    msg_.resp1 = std::move(arg);
    return Init_User_Response_resp2(msg_);
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
  return user_interfaces::srv::builder::Init_User_Response_resp1();
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
