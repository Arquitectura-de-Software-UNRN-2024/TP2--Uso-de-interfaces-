#include "../include/dynamic_mem_stack.hpp"
#include <cstdlib>

DynamicMemStack::DynamicMemStack()
    : count(0), stack(new StackableObject *[DYNAMIC_STACK_INITIAL_CAPACITY]),
      capacity(DYNAMIC_STACK_INITIAL_CAPACITY){};

DynamicMemStack::DynamicMemStack(size_t initial_capacity)
    : count(0), stack(new StackableObject *[initial_capacity]),
      capacity(initial_capacity){};

DynamicMemStack::~DynamicMemStack() {
    delete[] this->stack;
};

bool DynamicMemStack::push(StackableObject *const new_value) {
    if (!new_value) {
        return false;
    }
    if (count == capacity) {
        return false;
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

size_t DynamicMemStack::get_count() const {
    return this->count;
}
