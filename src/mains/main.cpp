#include "../../include/dummy_stackable_object.hpp"
#include "../../include/dynamic_mem_stack.hpp"
#include "../../include/dynamic_mem_stack_resizeable.hpp"
#include "../../include/fixed_array_stack.hpp"
#include "../../include/stack_user.hpp"
#include <cstring>
#include <exception>
#include <iostream>
#include <string>

const char *help_str = "aiuda";

int main(int argc, char *argv[]) {
  Stack *stack_impl = nullptr;
  if (argc > 1) {
    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
      std::cout << help_str << std::endl;
      exit(0);
    }
    if (strcmp(argv[1], "-f") == 0) {
      stack_impl = new FixedArrayStack();
    }
    int n = 0;
    if (argc > 2) {
      try {
        n = std::stoi(argv[2]);
      } catch (std::exception &e) {
        n = 0;
      }
    }
    if (strcmp(argv[1], "-d") == 0) {
      stack_impl = n < 1 ? new DynamicMemStack() : new DynamicMemStack(n);
    }
    if (strcmp(argv[1], "-r") == 0) {
      stack_impl = n < 1 ? new DynamicMemStackResizeable()
                         : new DynamicMemStackResizeable(n);
    }
  }
  if (!stack_impl) {
    stack_impl = new FixedArrayStack();
  }
  StackUser stack(stack_impl);
  stack_impl = nullptr;
  DummyStackableObject obj1;
  stack.push(&obj1);
  DummyStackableObject obj2;
  stack.push(&obj2);
  DummyStackableObject obj3;
  stack.push(&obj3);
  DummyStackableObject obj4;
  stack.push(&obj4);
  DummyStackableObject obj5;
  stack.push(&obj5);
  DummyStackableObject obj6;
  stack.push(&obj6);
  stack.print();
  return 0;
}
