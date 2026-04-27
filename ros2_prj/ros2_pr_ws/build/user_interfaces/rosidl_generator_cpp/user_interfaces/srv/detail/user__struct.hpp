// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from user_interfaces:srv/User.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "user_interfaces/srv/user.hpp"


#ifndef USER_INTERFACES__SRV__DETAIL__USER__STRUCT_HPP_
#define USER_INTERFACES__SRV__DETAIL__USER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__user_interfaces__srv__User_Request __attribute__((deprecated))
#else
# define DEPRECATED__user_interfaces__srv__User_Request __declspec(deprecated)
#endif

namespace user_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct User_Request_
{
  using Type = User_Request_<ContainerAllocator>;

  explicit User_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->out1 = "";
      this->out2 = 0ul;
    }
  }

  explicit User_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : out1(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->out1 = "";
      this->out2 = 0ul;
    }
  }

  // field types and members
  using _out1_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _out1_type out1;
  using _out2_type =
    uint32_t;
  _out2_type out2;

  // setters for named parameter idiom
  Type & set__out1(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->out1 = _arg;
    return *this;
  }
  Type & set__out2(
    const uint32_t & _arg)
  {
    this->out2 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    user_interfaces::srv::User_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const user_interfaces::srv::User_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<user_interfaces::srv::User_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<user_interfaces::srv::User_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      user_interfaces::srv::User_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<user_interfaces::srv::User_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      user_interfaces::srv::User_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<user_interfaces::srv::User_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<user_interfaces::srv::User_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<user_interfaces::srv::User_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__user_interfaces__srv__User_Request
    std::shared_ptr<user_interfaces::srv::User_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__user_interfaces__srv__User_Request
    std::shared_ptr<user_interfaces::srv::User_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const User_Request_ & other) const
  {
    if (this->out1 != other.out1) {
      return false;
    }
    if (this->out2 != other.out2) {
      return false;
    }
    return true;
  }
  bool operator!=(const User_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct User_Request_

// alias to use template instance with default allocator
using User_Request =
  user_interfaces::srv::User_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace user_interfaces


#ifndef _WIN32
# define DEPRECATED__user_interfaces__srv__User_Response __attribute__((deprecated))
#else
# define DEPRECATED__user_interfaces__srv__User_Response __declspec(deprecated)
#endif

namespace user_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct User_Response_
{
  using Type = User_Response_<ContainerAllocator>;

  explicit User_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->re1 = "";
      this->re2 = 0ul;
    }
  }

  explicit User_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : re1(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->re1 = "";
      this->re2 = 0ul;
    }
  }

  // field types and members
  using _re1_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _re1_type re1;
  using _re2_type =
    uint32_t;
  _re2_type re2;

  // setters for named parameter idiom
  Type & set__re1(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->re1 = _arg;
    return *this;
  }
  Type & set__re2(
    const uint32_t & _arg)
  {
    this->re2 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    user_interfaces::srv::User_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const user_interfaces::srv::User_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<user_interfaces::srv::User_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<user_interfaces::srv::User_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      user_interfaces::srv::User_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<user_interfaces::srv::User_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      user_interfaces::srv::User_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<user_interfaces::srv::User_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<user_interfaces::srv::User_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<user_interfaces::srv::User_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__user_interfaces__srv__User_Response
    std::shared_ptr<user_interfaces::srv::User_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__user_interfaces__srv__User_Response
    std::shared_ptr<user_interfaces::srv::User_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const User_Response_ & other) const
  {
    if (this->re1 != other.re1) {
      return false;
    }
    if (this->re2 != other.re2) {
      return false;
    }
    return true;
  }
  bool operator!=(const User_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct User_Response_

// alias to use template instance with default allocator
using User_Response =
  user_interfaces::srv::User_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace user_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__user_interfaces__srv__User_Event __attribute__((deprecated))
#else
# define DEPRECATED__user_interfaces__srv__User_Event __declspec(deprecated)
#endif

namespace user_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct User_Event_
{
  using Type = User_Event_<ContainerAllocator>;

  explicit User_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit User_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<user_interfaces::srv::User_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<user_interfaces::srv::User_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<user_interfaces::srv::User_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<user_interfaces::srv::User_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<user_interfaces::srv::User_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<user_interfaces::srv::User_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<user_interfaces::srv::User_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<user_interfaces::srv::User_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    user_interfaces::srv::User_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const user_interfaces::srv::User_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<user_interfaces::srv::User_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<user_interfaces::srv::User_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      user_interfaces::srv::User_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<user_interfaces::srv::User_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      user_interfaces::srv::User_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<user_interfaces::srv::User_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<user_interfaces::srv::User_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<user_interfaces::srv::User_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__user_interfaces__srv__User_Event
    std::shared_ptr<user_interfaces::srv::User_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__user_interfaces__srv__User_Event
    std::shared_ptr<user_interfaces::srv::User_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const User_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const User_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct User_Event_

// alias to use template instance with default allocator
using User_Event =
  user_interfaces::srv::User_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace user_interfaces

namespace user_interfaces
{

namespace srv
{

struct User
{
  using Request = user_interfaces::srv::User_Request;
  using Response = user_interfaces::srv::User_Response;
  using Event = user_interfaces::srv::User_Event;
};

}  // namespace srv

}  // namespace user_interfaces

#endif  // USER_INTERFACES__SRV__DETAIL__USER__STRUCT_HPP_
