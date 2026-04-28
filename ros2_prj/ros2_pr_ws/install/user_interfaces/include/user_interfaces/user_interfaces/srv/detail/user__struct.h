// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from user_interfaces:srv/User.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "user_interfaces/srv/user.h"


#ifndef USER_INTERFACES__SRV__DETAIL__USER__STRUCT_H_
#define USER_INTERFACES__SRV__DETAIL__USER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'req1'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/User in the package user_interfaces.
typedef struct user_interfaces__srv__User_Request
{
  rosidl_runtime_c__String req1;
  uint32_t req2;
} user_interfaces__srv__User_Request;

// Struct for a sequence of user_interfaces__srv__User_Request.
typedef struct user_interfaces__srv__User_Request__Sequence
{
  user_interfaces__srv__User_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} user_interfaces__srv__User_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'resp1'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/User in the package user_interfaces.
typedef struct user_interfaces__srv__User_Response
{
  rosidl_runtime_c__String resp1;
  uint32_t resp2;
} user_interfaces__srv__User_Response;

// Struct for a sequence of user_interfaces__srv__User_Response.
typedef struct user_interfaces__srv__User_Response__Sequence
{
  user_interfaces__srv__User_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} user_interfaces__srv__User_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  user_interfaces__srv__User_Event__request__MAX_SIZE = 1
};
// response
enum
{
  user_interfaces__srv__User_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/User in the package user_interfaces.
typedef struct user_interfaces__srv__User_Event
{
  service_msgs__msg__ServiceEventInfo info;
  user_interfaces__srv__User_Request__Sequence request;
  user_interfaces__srv__User_Response__Sequence response;
} user_interfaces__srv__User_Event;

// Struct for a sequence of user_interfaces__srv__User_Event.
typedef struct user_interfaces__srv__User_Event__Sequence
{
  user_interfaces__srv__User_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} user_interfaces__srv__User_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USER_INTERFACES__SRV__DETAIL__USER__STRUCT_H_
