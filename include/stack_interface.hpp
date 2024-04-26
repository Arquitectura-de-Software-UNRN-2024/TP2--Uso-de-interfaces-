/**
 * @file stack_interface.hpp
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
#include <cstddef>

class StackableObject {
public:
  virtual void print() = 0;
};

class Stack {
public:
  virtual bool push(StackableObject *const) = 0;
  virtual StackableObject *pop() = 0;
  virtual size_t get_count() const = 0;
};
