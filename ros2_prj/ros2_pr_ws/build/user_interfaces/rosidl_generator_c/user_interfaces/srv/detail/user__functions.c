// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from user_interfaces:srv/User.idl
// generated code does not contain a copyright notice
#include "user_interfaces/srv/detail/user__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `out1`
#include "rosidl_runtime_c/string_functions.h"

bool
user_interfaces__srv__User_Request__init(user_interfaces__srv__User_Request * msg)
{
  if (!msg) {
    return false;
  }
  // out1
  if (!rosidl_runtime_c__String__init(&msg->out1)) {
    user_interfaces__srv__User_Request__fini(msg);
    return false;
  }
  // out2
  return true;
}

void
user_interfaces__srv__User_Request__fini(user_interfaces__srv__User_Request * msg)
{
  if (!msg) {
    return;
  }
  // out1
  rosidl_runtime_c__String__fini(&msg->out1);
  // out2
}

bool
user_interfaces__srv__User_Request__are_equal(const user_interfaces__srv__User_Request * lhs, const user_interfaces__srv__User_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // out1
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->out1), &(rhs->out1)))
  {
    return false;
  }
  // out2
  if (lhs->out2 != rhs->out2) {
    return false;
  }
  return true;
}

bool
user_interfaces__srv__User_Request__copy(
  const user_interfaces__srv__User_Request * input,
  user_interfaces__srv__User_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // out1
  if (!rosidl_runtime_c__String__copy(
      &(input->out1), &(output->out1)))
  {
    return false;
  }
  // out2
  output->out2 = input->out2;
  return true;
}

user_interfaces__srv__User_Request *
user_interfaces__srv__User_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  user_interfaces__srv__User_Request * msg = (user_interfaces__srv__User_Request *)allocator.allocate(sizeof(user_interfaces__srv__User_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(user_interfaces__srv__User_Request));
  bool success = user_interfaces__srv__User_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
user_interfaces__srv__User_Request__destroy(user_interfaces__srv__User_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    user_interfaces__srv__User_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
user_interfaces__srv__User_Request__Sequence__init(user_interfaces__srv__User_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  user_interfaces__srv__User_Request * data = NULL;

  if (size) {
    data = (user_interfaces__srv__User_Request *)allocator.zero_allocate(size, sizeof(user_interfaces__srv__User_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = user_interfaces__srv__User_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        user_interfaces__srv__User_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
user_interfaces__srv__User_Request__Sequence__fini(user_interfaces__srv__User_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      user_interfaces__srv__User_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

user_interfaces__srv__User_Request__Sequence *
user_interfaces__srv__User_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  user_interfaces__srv__User_Request__Sequence * array = (user_interfaces__srv__User_Request__Sequence *)allocator.allocate(sizeof(user_interfaces__srv__User_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = user_interfaces__srv__User_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
user_interfaces__srv__User_Request__Sequence__destroy(user_interfaces__srv__User_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    user_interfaces__srv__User_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
user_interfaces__srv__User_Request__Sequence__are_equal(const user_interfaces__srv__User_Request__Sequence * lhs, const user_interfaces__srv__User_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!user_interfaces__srv__User_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
user_interfaces__srv__User_Request__Sequence__copy(
  const user_interfaces__srv__User_Request__Sequence * input,
  user_interfaces__srv__User_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(user_interfaces__srv__User_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    user_interfaces__srv__User_Request * data =
      (user_interfaces__srv__User_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!user_interfaces__srv__User_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          user_interfaces__srv__User_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!user_interfaces__srv__User_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `re1`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
user_interfaces__srv__User_Response__init(user_interfaces__srv__User_Response * msg)
{
  if (!msg) {
    return false;
  }
  // re1
  if (!rosidl_runtime_c__String__init(&msg->re1)) {
    user_interfaces__srv__User_Response__fini(msg);
    return false;
  }
  // re2
  return true;
}

void
user_interfaces__srv__User_Response__fini(user_interfaces__srv__User_Response * msg)
{
  if (!msg) {
    return;
  }
  // re1
  rosidl_runtime_c__String__fini(&msg->re1);
  // re2
}

bool
user_interfaces__srv__User_Response__are_equal(const user_interfaces__srv__User_Response * lhs, const user_interfaces__srv__User_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // re1
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->re1), &(rhs->re1)))
  {
    return false;
  }
  // re2
  if (lhs->re2 != rhs->re2) {
    return false;
  }
  return true;
}

bool
user_interfaces__srv__User_Response__copy(
  const user_interfaces__srv__User_Response * input,
  user_interfaces__srv__User_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // re1
  if (!rosidl_runtime_c__String__copy(
      &(input->re1), &(output->re1)))
  {
    return false;
  }
  // re2
  output->re2 = input->re2;
  return true;
}

user_interfaces__srv__User_Response *
user_interfaces__srv__User_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  user_interfaces__srv__User_Response * msg = (user_interfaces__srv__User_Response *)allocator.allocate(sizeof(user_interfaces__srv__User_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(user_interfaces__srv__User_Response));
  bool success = user_interfaces__srv__User_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
user_interfaces__srv__User_Response__destroy(user_interfaces__srv__User_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    user_interfaces__srv__User_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
user_interfaces__srv__User_Response__Sequence__init(user_interfaces__srv__User_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  user_interfaces__srv__User_Response * data = NULL;

  if (size) {
    data = (user_interfaces__srv__User_Response *)allocator.zero_allocate(size, sizeof(user_interfaces__srv__User_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = user_interfaces__srv__User_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        user_interfaces__srv__User_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
user_interfaces__srv__User_Response__Sequence__fini(user_interfaces__srv__User_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      user_interfaces__srv__User_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

user_interfaces__srv__User_Response__Sequence *
user_interfaces__srv__User_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  user_interfaces__srv__User_Response__Sequence * array = (user_interfaces__srv__User_Response__Sequence *)allocator.allocate(sizeof(user_interfaces__srv__User_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = user_interfaces__srv__User_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
user_interfaces__srv__User_Response__Sequence__destroy(user_interfaces__srv__User_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    user_interfaces__srv__User_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
user_interfaces__srv__User_Response__Sequence__are_equal(const user_interfaces__srv__User_Response__Sequence * lhs, const user_interfaces__srv__User_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!user_interfaces__srv__User_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
user_interfaces__srv__User_Response__Sequence__copy(
  const user_interfaces__srv__User_Response__Sequence * input,
  user_interfaces__srv__User_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(user_interfaces__srv__User_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    user_interfaces__srv__User_Response * data =
      (user_interfaces__srv__User_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!user_interfaces__srv__User_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          user_interfaces__srv__User_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!user_interfaces__srv__User_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "user_interfaces/srv/detail/user__functions.h"

bool
user_interfaces__srv__User_Event__init(user_interfaces__srv__User_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    user_interfaces__srv__User_Event__fini(msg);
    return false;
  }
  // request
  if (!user_interfaces__srv__User_Request__Sequence__init(&msg->request, 0)) {
    user_interfaces__srv__User_Event__fini(msg);
    return false;
  }
  // response
  if (!user_interfaces__srv__User_Response__Sequence__init(&msg->response, 0)) {
    user_interfaces__srv__User_Event__fini(msg);
    return false;
  }
  return true;
}

void
user_interfaces__srv__User_Event__fini(user_interfaces__srv__User_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  user_interfaces__srv__User_Request__Sequence__fini(&msg->request);
  // response
  user_interfaces__srv__User_Response__Sequence__fini(&msg->response);
}

bool
user_interfaces__srv__User_Event__are_equal(const user_interfaces__srv__User_Event * lhs, const user_interfaces__srv__User_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!user_interfaces__srv__User_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!user_interfaces__srv__User_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
user_interfaces__srv__User_Event__copy(
  const user_interfaces__srv__User_Event * input,
  user_interfaces__srv__User_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!user_interfaces__srv__User_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!user_interfaces__srv__User_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

user_interfaces__srv__User_Event *
user_interfaces__srv__User_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  user_interfaces__srv__User_Event * msg = (user_interfaces__srv__User_Event *)allocator.allocate(sizeof(user_interfaces__srv__User_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(user_interfaces__srv__User_Event));
  bool success = user_interfaces__srv__User_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
user_interfaces__srv__User_Event__destroy(user_interfaces__srv__User_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    user_interfaces__srv__User_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
user_interfaces__srv__User_Event__Sequence__init(user_interfaces__srv__User_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  user_interfaces__srv__User_Event * data = NULL;

  if (size) {
    data = (user_interfaces__srv__User_Event *)allocator.zero_allocate(size, sizeof(user_interfaces__srv__User_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = user_interfaces__srv__User_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        user_interfaces__srv__User_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
user_interfaces__srv__User_Event__Sequence__fini(user_interfaces__srv__User_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      user_interfaces__srv__User_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

user_interfaces__srv__User_Event__Sequence *
user_interfaces__srv__User_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  user_interfaces__srv__User_Event__Sequence * array = (user_interfaces__srv__User_Event__Sequence *)allocator.allocate(sizeof(user_interfaces__srv__User_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = user_interfaces__srv__User_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
user_interfaces__srv__User_Event__Sequence__destroy(user_interfaces__srv__User_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    user_interfaces__srv__User_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
user_interfaces__srv__User_Event__Sequence__are_equal(const user_interfaces__srv__User_Event__Sequence * lhs, const user_interfaces__srv__User_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!user_interfaces__srv__User_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
user_interfaces__srv__User_Event__Sequence__copy(
  const user_interfaces__srv__User_Event__Sequence * input,
  user_interfaces__srv__User_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(user_interfaces__srv__User_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    user_interfaces__srv__User_Event * data =
      (user_interfaces__srv__User_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!user_interfaces__srv__User_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          user_interfaces__srv__User_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!user_interfaces__srv__User_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
