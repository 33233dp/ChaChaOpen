// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from user_interfaces:srv/User.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "user_interfaces/srv/detail/user__functions.h"
#include "user_interfaces/srv/detail/user__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace user_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _User_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _User_Request_type_support_ids_t;

static const _User_Request_type_support_ids_t _User_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _User_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _User_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _User_Request_type_support_symbol_names_t _User_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, user_interfaces, srv, User_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, user_interfaces, srv, User_Request)),
  }
};

typedef struct _User_Request_type_support_data_t
{
  void * data[2];
} _User_Request_type_support_data_t;

static _User_Request_type_support_data_t _User_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _User_Request_message_typesupport_map = {
  2,
  "user_interfaces",
  &_User_Request_message_typesupport_ids.typesupport_identifier[0],
  &_User_Request_message_typesupport_symbol_names.symbol_name[0],
  &_User_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t User_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_User_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &user_interfaces__srv__User_Request__get_type_hash,
  &user_interfaces__srv__User_Request__get_type_description,
  &user_interfaces__srv__User_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace user_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<user_interfaces::srv::User_Request>()
{
  return &::user_interfaces::srv::rosidl_typesupport_cpp::User_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, user_interfaces, srv, User_Request)() {
  return get_message_type_support_handle<user_interfaces::srv::User_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "user_interfaces/srv/detail/user__functions.h"
// already included above
// #include "user_interfaces/srv/detail/user__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace user_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _User_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _User_Response_type_support_ids_t;

static const _User_Response_type_support_ids_t _User_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _User_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _User_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _User_Response_type_support_symbol_names_t _User_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, user_interfaces, srv, User_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, user_interfaces, srv, User_Response)),
  }
};

typedef struct _User_Response_type_support_data_t
{
  void * data[2];
} _User_Response_type_support_data_t;

static _User_Response_type_support_data_t _User_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _User_Response_message_typesupport_map = {
  2,
  "user_interfaces",
  &_User_Response_message_typesupport_ids.typesupport_identifier[0],
  &_User_Response_message_typesupport_symbol_names.symbol_name[0],
  &_User_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t User_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_User_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &user_interfaces__srv__User_Response__get_type_hash,
  &user_interfaces__srv__User_Response__get_type_description,
  &user_interfaces__srv__User_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace user_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<user_interfaces::srv::User_Response>()
{
  return &::user_interfaces::srv::rosidl_typesupport_cpp::User_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, user_interfaces, srv, User_Response)() {
  return get_message_type_support_handle<user_interfaces::srv::User_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "user_interfaces/srv/detail/user__functions.h"
// already included above
// #include "user_interfaces/srv/detail/user__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace user_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _User_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _User_Event_type_support_ids_t;

static const _User_Event_type_support_ids_t _User_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _User_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _User_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _User_Event_type_support_symbol_names_t _User_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, user_interfaces, srv, User_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, user_interfaces, srv, User_Event)),
  }
};

typedef struct _User_Event_type_support_data_t
{
  void * data[2];
} _User_Event_type_support_data_t;

static _User_Event_type_support_data_t _User_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _User_Event_message_typesupport_map = {
  2,
  "user_interfaces",
  &_User_Event_message_typesupport_ids.typesupport_identifier[0],
  &_User_Event_message_typesupport_symbol_names.symbol_name[0],
  &_User_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t User_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_User_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &user_interfaces__srv__User_Event__get_type_hash,
  &user_interfaces__srv__User_Event__get_type_description,
  &user_interfaces__srv__User_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace user_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<user_interfaces::srv::User_Event>()
{
  return &::user_interfaces::srv::rosidl_typesupport_cpp::User_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, user_interfaces, srv, User_Event)() {
  return get_message_type_support_handle<user_interfaces::srv::User_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "user_interfaces/srv/detail/user__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace user_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _User_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _User_type_support_ids_t;

static const _User_type_support_ids_t _User_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _User_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _User_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _User_type_support_symbol_names_t _User_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, user_interfaces, srv, User)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, user_interfaces, srv, User)),
  }
};

typedef struct _User_type_support_data_t
{
  void * data[2];
} _User_type_support_data_t;

static _User_type_support_data_t _User_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _User_service_typesupport_map = {
  2,
  "user_interfaces",
  &_User_service_typesupport_ids.typesupport_identifier[0],
  &_User_service_typesupport_symbol_names.symbol_name[0],
  &_User_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t User_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_User_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<user_interfaces::srv::User_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<user_interfaces::srv::User_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<user_interfaces::srv::User_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<user_interfaces::srv::User>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<user_interfaces::srv::User>,
  &user_interfaces__srv__User__get_type_hash,
  &user_interfaces__srv__User__get_type_description,
  &user_interfaces__srv__User__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace user_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<user_interfaces::srv::User>()
{
  return &::user_interfaces::srv::rosidl_typesupport_cpp::User_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, user_interfaces, srv, User)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<user_interfaces::srv::User>();
}

#ifdef __cplusplus
}
#endif
