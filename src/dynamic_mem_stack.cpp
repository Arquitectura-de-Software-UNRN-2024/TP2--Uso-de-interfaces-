#include "../include/dynamic_mem_stack.hpp"

DynamicMemStack::DynamicMemStack()
    : count(0), stack(new StackableObject* [DYNAMIC_STACK_INITIAL_CAPACITY]){};

DynamicMemStack::DynamicMemStack(size_t initial_count)
    : count(0), stack(new StackableObject* [initial_count]){};

DynamicMemStack::~DynamicMemStack() {
	delete[] stack;
};

bool DynamicMemStack::push(const StackableObject* new_value) {
	return true;
}
