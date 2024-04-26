/**
 * @file fixed_array_stack.hpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once
#include "stack_interface.hpp"

#ifndef FIXED_ARRAY_STACK_CAPACITY
#define FIXED_ARRAY_STACK_CAPACITY 10
#endif

class FixedArrayStack: public Stack{
    public:
        FixedArrayStack();
        ~FixedArrayStack() = default;
        FixedArrayStack(FixedArrayStack&&) = delete;
        FixedArrayStack(const FixedArrayStack&) = delete;
        FixedArrayStack &operator= (FixedArrayStack&&) = delete;
        FixedArrayStack &operator= (const FixedArrayStack&) = delete;

        virtual bool push(StackableObject *const) override;
        virtual StackableObject* pop() override;
        virtual size_t get_count() const override;
        
    private:
        StackableObject* stack[FIXED_ARRAY_STACK_CAPACITY];
        size_t count;
};
