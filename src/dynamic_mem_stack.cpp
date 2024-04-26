#include "../include/dynamic_mem_stack.hpp"
#include <cstdlib>

DynamicMemStack::DynamicMemStack()
    : count(0), new_arr(DynamicMemStack::default_new_arr),
      delete_arr(DynamicMemStack::default_delete_arr),
      stack(DynamicMemStack::default_new_arr(DYNAMIC_STACK_INITIAL_CAPACITY *
                                             sizeof(StackableObject *))),
      capacity(DYNAMIC_STACK_INITIAL_CAPACITY){};

DynamicMemStack::DynamicMemStack(size_t initial_capacity)
    : count(0), new_arr(DynamicMemStack::default_new_arr),
      delete_arr(DynamicMemStack::default_delete_arr),
      stack(DynamicMemStack::default_new_arr(initial_capacity *
                                             sizeof(StackableObject *))),
      capacity(initial_capacity){};

DynamicMemStack::DynamicMemStack(size_t initial_capacity,
                                 StackableObject **new_arr(size_t len),
                                 void delete_arr(StackableObject **ptr))
    : count(0), new_arr(new_arr), delete_arr(delete_arr),
      stack(new_arr(initial_capacity * sizeof(StackableObject *))),
      capacity(initial_capacity){};

DynamicMemStack::~DynamicMemStack() { this->delete_arr(stack); };

bool DynamicMemStack::push(StackableObject *const new_value) {
  if (!new_value) {
    return false;
  }
  if (count == capacity) {
    size_t new_capacity = capacity * 2;
    StackableObject **new_stack =
        (StackableObject **)realloc(stack, new_capacity);
    if (!new_stack) {
      return false;
    }
    this->stack = new_stack;
    this->capacity = new_capacity;
  }
  this->stack[this->count] = new_value;
  this->count++;
  return true;
}

StackableObject *DynamicMemStack::pop() {
  StackableObject *ret = nullptr;
  if (this->count > 0) {
    this->count--;
    ret = this->stack[this->count];
  }
  return ret;
}

size_t DynamicMemStack::get_count() const { return this->count; }

StackableObject **DynamicMemStack::default_new_arr(size_t len) {
  return (StackableObject **)malloc(len);
}
void DynamicMemStack::default_delete_arr(StackableObject **ptr) { free(ptr); }
