// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from user_interfaces:srv/User.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "user_interfaces/srv/detail/user__rosidl_typesupport_introspection_c.h"
#include "user_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "user_interfaces/srv/detail/user__functions.h"
#include "user_interfaces/srv/detail/user__struct.h"


// Include directives for member types
// Member `req1`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void user_interfaces__srv__User_Request__rosidl_typesupport_introspection_c__User_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  user_interfaces__srv__User_Request__init(message_memory);
}

void user_interfaces__srv__User_Request__rosidl_typesupport_introspection_c__User_Request_fini_function(void * message_memory)
{
  user_interfaces__srv__User_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember user_interfaces__srv__User_Request__rosidl_typesupport_introspection_c__User_Request_message_member_array[2] = {
  {
    "req1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_interfaces__srv__User_Request, req1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "req2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_interfaces__srv__User_Request, req2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers user_interfaces__srv__User_Request__rosidl_typesupport_introspection_c__User_Request_message_members = {
  "user_interfaces__srv",  // message namespace
  "User_Request",  // message name
  2,  // number of fields
  sizeof(user_interfaces__srv__User_Request),
  false,  // has_any_key_member_
  user_interfaces__srv__User_Request__rosidl_typesupport_introspection_c__User_Request_message_member_array,  // message members
  user_interfaces__srv__User_Request__rosidl_typesupport_introspection_c__User_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  user_interfaces__srv__User_Request__rosidl_typesupport_introspection_c__User_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t user_interfaces__srv__User_Request__rosidl_typesupport_introspection_c__User_Request_message_type_support_handle = {
  0,
  &user_interfaces__srv__User_Request__rosidl_typesupport_introspection_c__User_Request_message_members,
  get_message_typesupport_handle_function,
  &user_interfaces__srv__User_Request__get_type_hash,
  &user_interfaces__srv__User_Request__get_type_description,
  &user_interfaces__srv__User_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_user_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_interfaces, srv, User_Request)() {
  if (!user_interfaces__srv__User_Request__rosidl_typesupport_introspection_c__User_Request_message_type_support_handle.typesupport_identifier) {
    user_interfaces__srv__User_Request__rosidl_typesupport_introspection_c__User_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &user_interfaces__srv__User_Request__rosidl_typesupport_introspection_c__User_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "user_interfaces/srv/detail/user__rosidl_typesupport_introspection_c.h"
// already included above
// #include "user_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "user_interfaces/srv/detail/user__functions.h"
// already included above
// #include "user_interfaces/srv/detail/user__struct.h"


// Include directives for member types
// Member `resp1`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void user_interfaces__srv__User_Response__rosidl_typesupport_introspection_c__User_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  user_interfaces__srv__User_Response__init(message_memory);
}

void user_interfaces__srv__User_Response__rosidl_typesupport_introspection_c__User_Response_fini_function(void * message_memory)
{
  user_interfaces__srv__User_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember user_interfaces__srv__User_Response__rosidl_typesupport_introspection_c__User_Response_message_member_array[2] = {
  {
    "resp1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_interfaces__srv__User_Response, resp1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "resp2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_interfaces__srv__User_Response, resp2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers user_interfaces__srv__User_Response__rosidl_typesupport_introspection_c__User_Response_message_members = {
  "user_interfaces__srv",  // message namespace
  "User_Response",  // message name
  2,  // number of fields
  sizeof(user_interfaces__srv__User_Response),
  false,  // has_any_key_member_
  user_interfaces__srv__User_Response__rosidl_typesupport_introspection_c__User_Response_message_member_array,  // message members
  user_interfaces__srv__User_Response__rosidl_typesupport_introspection_c__User_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  user_interfaces__srv__User_Response__rosidl_typesupport_introspection_c__User_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t user_interfaces__srv__User_Response__rosidl_typesupport_introspection_c__User_Response_message_type_support_handle = {
  0,
  &user_interfaces__srv__User_Response__rosidl_typesupport_introspection_c__User_Response_message_members,
  get_message_typesupport_handle_function,
  &user_interfaces__srv__User_Response__get_type_hash,
  &user_interfaces__srv__User_Response__get_type_description,
  &user_interfaces__srv__User_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_user_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_interfaces, srv, User_Response)() {
  if (!user_interfaces__srv__User_Response__rosidl_typesupport_introspection_c__User_Response_message_type_support_handle.typesupport_identifier) {
    user_interfaces__srv__User_Response__rosidl_typesupport_introspection_c__User_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &user_interfaces__srv__User_Response__rosidl_typesupport_introspection_c__User_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "user_interfaces/srv/detail/user__rosidl_typesupport_introspection_c.h"
// already included above
// #include "user_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "user_interfaces/srv/detail/user__functions.h"
// already included above
// #include "user_interfaces/srv/detail/user__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "user_interfaces/srv/user.h"
// Member `request`
// Member `response`
// already included above
// #include "user_interfaces/srv/detail/user__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__User_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  user_interfaces__srv__User_Event__init(message_memory);
}

void user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__User_Event_fini_function(void * message_memory)
{
  user_interfaces__srv__User_Event__fini(message_memory);
}

size_t user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__size_function__User_Event__request(
  const void * untyped_member)
{
  const user_interfaces__srv__User_Request__Sequence * member =
    (const user_interfaces__srv__User_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__get_const_function__User_Event__request(
  const void * untyped_member, size_t index)
{
  const user_interfaces__srv__User_Request__Sequence * member =
    (const user_interfaces__srv__User_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__get_function__User_Event__request(
  void * untyped_member, size_t index)
{
  user_interfaces__srv__User_Request__Sequence * member =
    (user_interfaces__srv__User_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__fetch_function__User_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const user_interfaces__srv__User_Request * item =
    ((const user_interfaces__srv__User_Request *)
    user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__get_const_function__User_Event__request(untyped_member, index));
  user_interfaces__srv__User_Request * value =
    (user_interfaces__srv__User_Request *)(untyped_value);
  *value = *item;
}

void user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__assign_function__User_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  user_interfaces__srv__User_Request * item =
    ((user_interfaces__srv__User_Request *)
    user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__get_function__User_Event__request(untyped_member, index));
  const user_interfaces__srv__User_Request * value =
    (const user_interfaces__srv__User_Request *)(untyped_value);
  *item = *value;
}

bool user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__resize_function__User_Event__request(
  void * untyped_member, size_t size)
{
  user_interfaces__srv__User_Request__Sequence * member =
    (user_interfaces__srv__User_Request__Sequence *)(untyped_member);
  user_interfaces__srv__User_Request__Sequence__fini(member);
  return user_interfaces__srv__User_Request__Sequence__init(member, size);
}

size_t user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__size_function__User_Event__response(
  const void * untyped_member)
{
  const user_interfaces__srv__User_Response__Sequence * member =
    (const user_interfaces__srv__User_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__get_const_function__User_Event__response(
  const void * untyped_member, size_t index)
{
  const user_interfaces__srv__User_Response__Sequence * member =
    (const user_interfaces__srv__User_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__get_function__User_Event__response(
  void * untyped_member, size_t index)
{
  user_interfaces__srv__User_Response__Sequence * member =
    (user_interfaces__srv__User_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__fetch_function__User_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const user_interfaces__srv__User_Response * item =
    ((const user_interfaces__srv__User_Response *)
    user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__get_const_function__User_Event__response(untyped_member, index));
  user_interfaces__srv__User_Response * value =
    (user_interfaces__srv__User_Response *)(untyped_value);
  *value = *item;
}

void user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__assign_function__User_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  user_interfaces__srv__User_Response * item =
    ((user_interfaces__srv__User_Response *)
    user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__get_function__User_Event__response(untyped_member, index));
  const user_interfaces__srv__User_Response * value =
    (const user_interfaces__srv__User_Response *)(untyped_value);
  *item = *value;
}

bool user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__resize_function__User_Event__response(
  void * untyped_member, size_t size)
{
  user_interfaces__srv__User_Response__Sequence * member =
    (user_interfaces__srv__User_Response__Sequence *)(untyped_member);
  user_interfaces__srv__User_Response__Sequence__fini(member);
  return user_interfaces__srv__User_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__User_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_interfaces__srv__User_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(user_interfaces__srv__User_Event, request),  // bytes offset in struct
    NULL,  // default value
    user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__size_function__User_Event__request,  // size() function pointer
    user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__get_const_function__User_Event__request,  // get_const(index) function pointer
    user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__get_function__User_Event__request,  // get(index) function pointer
    user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__fetch_function__User_Event__request,  // fetch(index, &value) function pointer
    user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__assign_function__User_Event__request,  // assign(index, value) function pointer
    user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__resize_function__User_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(user_interfaces__srv__User_Event, response),  // bytes offset in struct
    NULL,  // default value
    user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__size_function__User_Event__response,  // size() function pointer
    user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__get_const_function__User_Event__response,  // get_const(index) function pointer
    user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__get_function__User_Event__response,  // get(index) function pointer
    user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__fetch_function__User_Event__response,  // fetch(index, &value) function pointer
    user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__assign_function__User_Event__response,  // assign(index, value) function pointer
    user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__resize_function__User_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__User_Event_message_members = {
  "user_interfaces__srv",  // message namespace
  "User_Event",  // message name
  3,  // number of fields
  sizeof(user_interfaces__srv__User_Event),
  false,  // has_any_key_member_
  user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__User_Event_message_member_array,  // message members
  user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__User_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__User_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__User_Event_message_type_support_handle = {
  0,
  &user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__User_Event_message_members,
  get_message_typesupport_handle_function,
  &user_interfaces__srv__User_Event__get_type_hash,
  &user_interfaces__srv__User_Event__get_type_description,
  &user_interfaces__srv__User_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_user_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_interfaces, srv, User_Event)() {
  user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__User_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__User_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_interfaces, srv, User_Request)();
  user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__User_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_interfaces, srv, User_Response)();
  if (!user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__User_Event_message_type_support_handle.typesupport_identifier) {
    user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__User_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__User_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "user_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "user_interfaces/srv/detail/user__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers user_interfaces__srv__detail__user__rosidl_typesupport_introspection_c__User_service_members = {
  "user_interfaces__srv",  // service namespace
  "User",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // user_interfaces__srv__detail__user__rosidl_typesupport_introspection_c__User_Request_message_type_support_handle,
  NULL,  // response message
  // user_interfaces__srv__detail__user__rosidl_typesupport_introspection_c__User_Response_message_type_support_handle
  NULL  // event_message
  // user_interfaces__srv__detail__user__rosidl_typesupport_introspection_c__User_Response_message_type_support_handle
};


static rosidl_service_type_support_t user_interfaces__srv__detail__user__rosidl_typesupport_introspection_c__User_service_type_support_handle = {
  0,
  &user_interfaces__srv__detail__user__rosidl_typesupport_introspection_c__User_service_members,
  get_service_typesupport_handle_function,
  &user_interfaces__srv__User_Request__rosidl_typesupport_introspection_c__User_Request_message_type_support_handle,
  &user_interfaces__srv__User_Response__rosidl_typesupport_introspection_c__User_Response_message_type_support_handle,
  &user_interfaces__srv__User_Event__rosidl_typesupport_introspection_c__User_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    user_interfaces,
    srv,
    User
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    user_interfaces,
    srv,
    User
  ),
  &user_interfaces__srv__User__get_type_hash,
  &user_interfaces__srv__User__get_type_description,
  &user_interfaces__srv__User__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_interfaces, srv, User_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_interfaces, srv, User_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_interfaces, srv, User_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_user_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_interfaces, srv, User)(void) {
  if (!user_interfaces__srv__detail__user__rosidl_typesupport_introspection_c__User_service_type_support_handle.typesupport_identifier) {
    user_interfaces__srv__detail__user__rosidl_typesupport_introspection_c__User_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)user_interfaces__srv__detail__user__rosidl_typesupport_introspection_c__User_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_interfaces, srv, User_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_interfaces, srv, User_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_interfaces, srv, User_Event)()->data;
  }

  return &user_interfaces__srv__detail__user__rosidl_typesupport_introspection_c__User_service_type_support_handle;
}
