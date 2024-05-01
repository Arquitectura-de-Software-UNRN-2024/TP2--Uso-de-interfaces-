/**
 * @file stack_user.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-04-26
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/stack_user.hpp"

StackUser::StackUser(Stack *foreing_stack) : stack{foreing_stack} {}

bool StackUser::push(StackableObject *const new_object) {
  return this->stack->push(new_object);
}

void StackUser::print() {
  for (StackableObject *obj = this->stack->pop(); obj != nullptr;
       obj = this->stack->pop()) {
	  obj->print();
  }
}
