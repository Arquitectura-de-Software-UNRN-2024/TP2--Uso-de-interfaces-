/**
 * @file stack_user.hpp
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
#include <memory>

class StackUser {
  public:
    StackUser(Stack *);
    StackUser(StackUser &&) = delete;
    StackUser(const StackUser &) = delete;
    StackUser &operator=(StackUser &&) = delete;
    StackUser &operator=(const StackUser &) = delete;
    ~StackUser() = default;

    bool push(StackableObject *const);
    void print();

  private:
    std::unique_ptr<Stack> stack;
};
