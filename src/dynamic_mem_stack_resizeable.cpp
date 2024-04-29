#include "../include/dynamic_mem_stack_resizeable.hpp"
#include <cstdlib>

DynamicMemStackResizeable::DynamicMemStackResizeable()
    : count(0), stack(), capacity(DYNAMIC_STACK_INITIAL_CAPACITY) {
  stack.reserve(DYNAMIC_STACK_INITIAL_CAPACITY);
};

DynamicMemStackResizeable::DynamicMemStackResizeable(size_t initial_capacity)
    : count(0), stack(), capacity(initial_capacity) {
  stack.reserve(initial_capacity);
};

DynamicMemStackResizeable::~DynamicMemStackResizeable(){};

bool DynamicMemStackResizeable::push(StackableObject *const new_value) {
  if (!new_value) {
    return false;
  }
  try {
    this->stack.push_back(new_value);
  } catch (const std::exception &e) {
    return false;
  }
  this->count++;
  return true;
}

StackableObject *DynamicMemStackResizeable::pop() {
  StackableObject *ret = nullptr;
  if (this->count > 0) {
    this->count--;
    ret = this->stack[this->count];
  }
  return ret;
}

size_t DynamicMemStackResizeable::get_count() const { return this->count; }
