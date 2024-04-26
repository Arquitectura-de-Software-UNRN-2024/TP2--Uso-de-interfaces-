#pragma once
#include "stack_interface.hpp"

class DynamicMemStack : public Stack {
public:
	DynamicMemStack() = default;
	DynamicMemStack(DynamicMemStack &&) = delete;
	DynamicMemStack(const DynamicMemStack &) = delete;
	DynamicMemStack &operator=(DynamicMemStack &&) = delete;
	DynamicMemStack &operator=(const DynamicMemStack &) = delete;
	~DynamicMemStack() = default;

	virtual bool push(StackableObject*) override;
	virtual StackableObject* pop() override;
	virtual size_t get_count() override;


private:
	StackableObject** stack;
	size_t count;
};
