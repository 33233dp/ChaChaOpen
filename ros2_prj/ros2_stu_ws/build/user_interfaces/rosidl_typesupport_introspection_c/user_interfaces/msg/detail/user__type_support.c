// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from user_interfaces:msg/User.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "user_interfaces/msg/detail/user__rosidl_typesupport_introspection_c.h"
#include "user_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "user_interfaces/msg/detail/user__functions.h"
#include "user_interfaces/msg/detail/user__struct.h"


// Include directives for member types
// Member `user_msg`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void user_interfaces__msg__User__rosidl_typesupport_introspection_c__User_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  user_interfaces__msg__User__init(message_memory);
}

void user_interfaces__msg__User__rosidl_typesupport_introspection_c__User_fini_function(void * message_memory)
{
  user_interfaces__msg__User__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember user_interfaces__msg__User__rosidl_typesupport_introspection_c__User_message_member_array[1] = {
  {
    "user_msg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_interfaces__msg__User, user_msg),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers user_interfaces__msg__User__rosidl_typesupport_introspection_c__User_message_members = {
  "user_interfaces__msg",  // message namespace
  "User",  // message name
  1,  // number of fields
  sizeof(user_interfaces__msg__User),
  false,  // has_any_key_member_
  user_interfaces__msg__User__rosidl_typesupport_introspection_c__User_message_member_array,  // message members
  user_interfaces__msg__User__rosidl_typesupport_introspection_c__User_init_function,  // function to initialize message memory (memory has to be allocated)
  user_interfaces__msg__User__rosidl_typesupport_introspection_c__User_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t user_interfaces__msg__User__rosidl_typesupport_introspection_c__User_message_type_support_handle = {
  0,
  &user_interfaces__msg__User__rosidl_typesupport_introspection_c__User_message_members,
  get_message_typesupport_handle_function,
  &user_interfaces__msg__User__get_type_hash,
  &user_interfaces__msg__User__get_type_description,
  &user_interfaces__msg__User__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_user_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_interfaces, msg, User)() {
  if (!user_interfaces__msg__User__rosidl_typesupport_introspection_c__User_message_type_support_handle.typesupport_identifier) {
    user_interfaces__msg__User__rosidl_typesupport_introspection_c__User_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &user_interfaces__msg__User__rosidl_typesupport_introspection_c__User_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
