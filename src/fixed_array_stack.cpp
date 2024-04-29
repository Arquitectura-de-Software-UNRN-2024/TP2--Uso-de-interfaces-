/**
 * @file fixed_array_stack.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/fixed_array_stack.hpp"

FixedArrayStack::FixedArrayStack():count(0),stack{} {}

bool FixedArrayStack::push(StackableObject *const new_object){
    if (!new_object){
        return false;
    }
    if (this->count >= FIXED_ARRAY_STACK_CAPACITY){
        return false;
    }
    this->stack[this->count] = new_object;
    this->count++;
    return true;
    
}

StackableObject* FixedArrayStack::pop(){
    StackableObject* poppedobject = nullptr;
    if (this->count > 0){
        this->count--;
        poppedobject = this->stack[this->count];
    }
    return poppedobject;
    
}

size_t FixedArrayStack::get_count() const { return this->count; }
