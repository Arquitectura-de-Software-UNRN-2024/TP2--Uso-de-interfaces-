#pragma once
#include "stack_interface.hpp"
#include <vector>

#ifndef DYNAMIC_STACK_INITIAL_CAPACITY
#define DYNAMIC_STACK_INITIAL_CAPACITY 10
#endif // !DYNAMIC_STACK_INITIAL_CAPACITY

class DynamicMemStackResizeable : public Stack {
  public:
    DynamicMemStackResizeable();
    DynamicMemStackResizeable(size_t);
    DynamicMemStackResizeable(size_t, StackableObject **new_arr(size_t len),
                              void delete_arr(StackableObject **ptr));
    DynamicMemStackResizeable(DynamicMemStackResizeable &&) = delete;
    DynamicMemStackResizeable(const DynamicMemStackResizeable &) = delete;
    DynamicMemStackResizeable &operator=(DynamicMemStackResizeable &&) = delete;
    DynamicMemStackResizeable &
    operator=(const DynamicMemStackResizeable &) = delete;
    ~DynamicMemStackResizeable();

    virtual bool push(StackableObject *const) override;
    virtual StackableObject *pop() override;
    virtual size_t get_count() const override;

  private:
    std::vector<StackableObject *> stack;
    size_t count;
    size_t capacity;
};
