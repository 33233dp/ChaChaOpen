// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from user_interfaces:msg/User.idl
// generated code does not contain a copyright notice
#include "user_interfaces/msg/detail/user__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `msg_content`
#include "rosidl_runtime_c/string_functions.h"
// Member `content`
#include "std_msgs/msg/detail/string__functions.h"
// Member `image`
#include "sensor_msgs/msg/detail/image__functions.h"

bool
user_interfaces__msg__User__init(user_interfaces__msg__User * msg)
{
  if (!msg) {
    return false;
  }
  // msg_content
  if (!rosidl_runtime_c__String__init(&msg->msg_content)) {
    user_interfaces__msg__User__fini(msg);
    return false;
  }
  // content
  if (!std_msgs__msg__String__init(&msg->content)) {
    user_interfaces__msg__User__fini(msg);
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__init(&msg->image)) {
    user_interfaces__msg__User__fini(msg);
    return false;
  }
  return true;
}

void
user_interfaces__msg__User__fini(user_interfaces__msg__User * msg)
{
  if (!msg) {
    return;
  }
  // msg_content
  rosidl_runtime_c__String__fini(&msg->msg_content);
  // content
  std_msgs__msg__String__fini(&msg->content);
  // image
  sensor_msgs__msg__Image__fini(&msg->image);
}

bool
user_interfaces__msg__User__are_equal(const user_interfaces__msg__User * lhs, const user_interfaces__msg__User * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // msg_content
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->msg_content), &(rhs->msg_content)))
  {
    return false;
  }
  // content
  if (!std_msgs__msg__String__are_equal(
      &(lhs->content), &(rhs->content)))
  {
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->image), &(rhs->image)))
  {
    return false;
  }
  return true;
}

bool
user_interfaces__msg__User__copy(
  const user_interfaces__msg__User * input,
  user_interfaces__msg__User * output)
{
  if (!input || !output) {
    return false;
  }
  // msg_content
  if (!rosidl_runtime_c__String__copy(
      &(input->msg_content), &(output->msg_content)))
  {
    return false;
  }
  // content
  if (!std_msgs__msg__String__copy(
      &(input->content), &(output->content)))
  {
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__copy(
      &(input->image), &(output->image)))
  {
    return false;
  }
  return true;
}

user_interfaces__msg__User *
user_interfaces__msg__User__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  user_interfaces__msg__User * msg = (user_interfaces__msg__User *)allocator.allocate(sizeof(user_interfaces__msg__User), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(user_interfaces__msg__User));
  bool success = user_interfaces__msg__User__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
user_interfaces__msg__User__destroy(user_interfaces__msg__User * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    user_interfaces__msg__User__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
user_interfaces__msg__User__Sequence__init(user_interfaces__msg__User__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  user_interfaces__msg__User * data = NULL;

  if (size) {
    data = (user_interfaces__msg__User *)allocator.zero_allocate(size, sizeof(user_interfaces__msg__User), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = user_interfaces__msg__User__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        user_interfaces__msg__User__fini(&data[i - 1]);
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
user_interfaces__msg__User__Sequence__fini(user_interfaces__msg__User__Sequence * array)
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
      user_interfaces__msg__User__fini(&array->data[i]);
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

user_interfaces__msg__User__Sequence *
user_interfaces__msg__User__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  user_interfaces__msg__User__Sequence * array = (user_interfaces__msg__User__Sequence *)allocator.allocate(sizeof(user_interfaces__msg__User__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = user_interfaces__msg__User__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
user_interfaces__msg__User__Sequence__destroy(user_interfaces__msg__User__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    user_interfaces__msg__User__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
user_interfaces__msg__User__Sequence__are_equal(const user_interfaces__msg__User__Sequence * lhs, const user_interfaces__msg__User__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!user_interfaces__msg__User__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
user_interfaces__msg__User__Sequence__copy(
  const user_interfaces__msg__User__Sequence * input,
  user_interfaces__msg__User__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(user_interfaces__msg__User);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    user_interfaces__msg__User * data =
      (user_interfaces__msg__User *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!user_interfaces__msg__User__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          user_interfaces__msg__User__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!user_interfaces__msg__User__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
