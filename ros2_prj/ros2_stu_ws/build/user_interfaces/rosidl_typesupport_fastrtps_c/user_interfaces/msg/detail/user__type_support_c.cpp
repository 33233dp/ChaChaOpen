// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from user_interfaces:msg/User.idl
// generated code does not contain a copyright notice
#include "user_interfaces/msg/detail/user__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "user_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "user_interfaces/msg/detail/user__struct.h"
#include "user_interfaces/msg/detail/user__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // user_msg
#include "rosidl_runtime_c/string_functions.h"  // user_msg

// forward declare type support functions


using _User__ros_msg_type = user_interfaces__msg__User;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_interfaces
bool cdr_serialize_user_interfaces__msg__User(
  const user_interfaces__msg__User * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: user_msg
  {
    const rosidl_runtime_c__String * str = &ros_message->user_msg;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_interfaces
bool cdr_deserialize_user_interfaces__msg__User(
  eprosima::fastcdr::Cdr & cdr,
  user_interfaces__msg__User * ros_message)
{
  // Field name: user_msg
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->user_msg.data) {
      rosidl_runtime_c__String__init(&ros_message->user_msg);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->user_msg,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'user_msg'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_interfaces
size_t get_serialized_size_user_interfaces__msg__User(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _User__ros_msg_type * ros_message = static_cast<const _User__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: user_msg
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->user_msg.size + 1);

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_interfaces
size_t max_serialized_size_user_interfaces__msg__User(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: user_msg
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = user_interfaces__msg__User;
    is_plain =
      (
      offsetof(DataType, user_msg) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_interfaces
bool cdr_serialize_key_user_interfaces__msg__User(
  const user_interfaces__msg__User * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: user_msg
  {
    const rosidl_runtime_c__String * str = &ros_message->user_msg;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_interfaces
size_t get_serialized_size_key_user_interfaces__msg__User(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _User__ros_msg_type * ros_message = static_cast<const _User__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: user_msg
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->user_msg.size + 1);

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_interfaces
size_t max_serialized_size_key_user_interfaces__msg__User(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: user_msg
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = user_interfaces__msg__User;
    is_plain =
      (
      offsetof(DataType, user_msg) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _User__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const user_interfaces__msg__User * ros_message = static_cast<const user_interfaces__msg__User *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_user_interfaces__msg__User(ros_message, cdr);
}

static bool _User__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  user_interfaces__msg__User * ros_message = static_cast<user_interfaces__msg__User *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_user_interfaces__msg__User(cdr, ros_message);
}

static uint32_t _User__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_user_interfaces__msg__User(
      untyped_ros_message, 0));
}

static size_t _User__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_user_interfaces__msg__User(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_User = {
  "user_interfaces::msg",
  "User",
  _User__cdr_serialize,
  _User__cdr_deserialize,
  _User__get_serialized_size,
  _User__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _User__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_User,
  get_message_typesupport_handle_function,
  &user_interfaces__msg__User__get_type_hash,
  &user_interfaces__msg__User__get_type_description,
  &user_interfaces__msg__User__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_interfaces, msg, User)() {
  return &_User__type_support;
}

#if defined(__cplusplus)
}
#endif
