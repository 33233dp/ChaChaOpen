// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from user_interfaces:msg/User.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "user_interfaces/msg/user.h"


#ifndef USER_INTERFACES__MSG__DETAIL__USER__STRUCT_H_
#define USER_INTERFACES__MSG__DETAIL__USER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'user_msg'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/User in the package user_interfaces.
/**
  * 使用ros2的原始数据类型
 */
typedef struct user_interfaces__msg__User
{
  rosidl_runtime_c__String user_msg;
} user_interfaces__msg__User;

// Struct for a sequence of user_interfaces__msg__User.
typedef struct user_interfaces__msg__User__Sequence
{
  user_interfaces__msg__User * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} user_interfaces__msg__User__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USER_INTERFACES__MSG__DETAIL__USER__STRUCT_H_
