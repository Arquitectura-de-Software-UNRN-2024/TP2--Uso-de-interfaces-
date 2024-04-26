#pragma once
#include "stack_interface.hpp"

#ifndef DYNAMIC_STACK_INITIAL_CAPACITY
#define DYNAMIC_STACK_INITIAL_CAPACITY 10
#endif // !DYNAMIC_STACK_INITIAL_CAPACITY

class DynamicMemStack : public Stack {
public:
	DynamicMemStack();
	DynamicMemStack(size_t);
	DynamicMemStack(DynamicMemStack &&) = delete;
	DynamicMemStack(const DynamicMemStack &) = delete;
	DynamicMemStack &operator=(DynamicMemStack &&) = delete;
	DynamicMemStack &operator=(const DynamicMemStack &) = delete;
	~DynamicMemStack();

	virtual bool push(const StackableObject*) override;
	virtual StackableObject* pop() override;
	virtual size_t get_count() const override;

	StackableObject** stack;
	size_t count;
};
