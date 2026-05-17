// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from user_interfaces:msg/User.idl
// generated code does not contain a copyright notice

#include "user_interfaces/msg/detail/user__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_user_interfaces
const rosidl_type_hash_t *
user_interfaces__msg__User__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x90, 0xd8, 0x1f, 0x2d, 0xa7, 0x23, 0xed, 0xef,
      0xa2, 0xbc, 0x5c, 0x78, 0xca, 0xf1, 0xd9, 0xd6,
      0x55, 0x5f, 0x70, 0x85, 0xc3, 0x60, 0x16, 0xdd,
      0xbd, 0xa4, 0x70, 0x15, 0x04, 0xce, 0x69, 0xad,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char user_interfaces__msg__User__TYPE_NAME[] = "user_interfaces/msg/User";

// Define type names, field names, and default values
static char user_interfaces__msg__User__FIELD_NAME__user_msg[] = "user_msg";

static rosidl_runtime_c__type_description__Field user_interfaces__msg__User__FIELDS[] = {
  {
    {user_interfaces__msg__User__FIELD_NAME__user_msg, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
user_interfaces__msg__User__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {user_interfaces__msg__User__TYPE_NAME, 24, 24},
      {user_interfaces__msg__User__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# \\xe4\\xbd\\xbf\\xe7\\x94\\xa8ros2\\xe7\\x9a\\x84\\xe5\\x8e\\x9f\\xe5\\xa7\\x8b\\xe6\\x95\\xb0\\xe6\\x8d\\xae\\xe7\\xb1\\xbb\\xe5\\x9e\\x8b\n"
  "string user_msg";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
user_interfaces__msg__User__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {user_interfaces__msg__User__TYPE_NAME, 24, 24},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 31, 31},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
user_interfaces__msg__User__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *user_interfaces__msg__User__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
