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
      0x72, 0x2a, 0x30, 0x24, 0x94, 0x84, 0xbd, 0x77,
      0xe2, 0xd4, 0x37, 0xcd, 0xc9, 0x99, 0x1f, 0x02,
      0x50, 0xcb, 0xa0, 0x9e, 0x16, 0x4a, 0x0c, 0xb3,
      0x01, 0x36, 0xaa, 0x7f, 0x24, 0x86, 0x53, 0x6d,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "std_msgs/msg/detail/string__functions.h"
#include "std_msgs/msg/detail/header__functions.h"
#include "sensor_msgs/msg/detail/image__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t sensor_msgs__msg__Image__EXPECTED_HASH = {1, {
    0xd3, 0x1d, 0x41, 0xa9, 0xa4, 0xc4, 0xbc, 0x8e,
    0xae, 0x9b, 0xe7, 0x57, 0xb0, 0xbe, 0xed, 0x30,
    0x65, 0x64, 0xf7, 0x52, 0x6c, 0x88, 0xea, 0x6a,
    0x45, 0x88, 0xfb, 0x95, 0x82, 0x52, 0x7d, 0x47,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
static const rosidl_type_hash_t std_msgs__msg__String__EXPECTED_HASH = {1, {
    0xdf, 0x66, 0x8c, 0x74, 0x04, 0x82, 0xbb, 0xd4,
    0x8f, 0xb3, 0x9d, 0x76, 0xa7, 0x0d, 0xfd, 0x4b,
    0xd5, 0x9d, 0xb1, 0x28, 0x80, 0x21, 0x74, 0x35,
    0x03, 0x25, 0x9e, 0x94, 0x8f, 0x6b, 0x1a, 0x18,
  }};
#endif

static char user_interfaces__msg__User__TYPE_NAME[] = "user_interfaces/msg/User";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char sensor_msgs__msg__Image__TYPE_NAME[] = "sensor_msgs/msg/Image";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";
static char std_msgs__msg__String__TYPE_NAME[] = "std_msgs/msg/String";

// Define type names, field names, and default values
static char user_interfaces__msg__User__FIELD_NAME__msg_content[] = "msg_content";
static char user_interfaces__msg__User__FIELD_NAME__content[] = "content";
static char user_interfaces__msg__User__FIELD_NAME__image[] = "image";

static rosidl_runtime_c__type_description__Field user_interfaces__msg__User__FIELDS[] = {
  {
    {user_interfaces__msg__User__FIELD_NAME__msg_content, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {user_interfaces__msg__User__FIELD_NAME__content, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__String__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {user_interfaces__msg__User__FIELD_NAME__image, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {sensor_msgs__msg__Image__TYPE_NAME, 21, 21},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription user_interfaces__msg__User__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {sensor_msgs__msg__Image__TYPE_NAME, 21, 21},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__String__TYPE_NAME, 19, 19},
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
      {user_interfaces__msg__User__FIELDS, 3, 3},
    },
    {user_interfaces__msg__User__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&sensor_msgs__msg__Image__EXPECTED_HASH, sensor_msgs__msg__Image__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = sensor_msgs__msg__Image__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__String__EXPECTED_HASH, std_msgs__msg__String__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = std_msgs__msg__String__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# \\xe7\\x9b\\xb4\\xe6\\x8e\\xa5\\xe4\\xbd\\xbf\\xe7\\x94\\xa8ros2\\xe5\\x8e\\x9f\\xe5\\xa7\\x8b\\xe6\\x95\\xb0\\xe6\\x8d\\xae\\xe7\\xb1\\xbb\\xe5\\x9e\\x8b\n"
  "string msg_content\n"
  "# \\xe6\\xa0\\x87\\xe5\\x87\\x86\\xe6\\xb6\\x88\\xe6\\x81\\xaf\\xe6\\x8e\\xa5\\xe5\\x8f\\xa3std_msgs\\xe4\\xb8\\x8b\\xe7\\x9a\\x84String\\xe7\\xb1\\xbb\\xe5\\x9e\\x8b\n"
  "std_msgs/String content\n"
  "# \\xe5\\x9b\\xbe\\xe5\\x83\\x8f\\xe6\\xb6\\x88\\xe6\\x81\\xaf\\xef\\xbc\\x8c\\xe8\\xb0\\x83\\xe7\\x94\\xa8sensor_msgs\\xe4\\xb8\\x8b\\xe7\\x9a\\x84Image\\xe7\\xb1\\xbb\\xe5\\x9e\\x8b\n"
  "sensor_msgs/Image image";

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
    {toplevel_type_raw_source, 141, 141},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
user_interfaces__msg__User__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *user_interfaces__msg__User__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *sensor_msgs__msg__Image__get_individual_type_description_source(NULL);
    sources[3] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    sources[4] = *std_msgs__msg__String__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
