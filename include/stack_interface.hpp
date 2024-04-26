#pragma once
#include <cstddef>

class StackableObject {
public:
  void print();
};

class Stack {
public:
  bool push(StackableObject*);
  StackableObject* pop();
  size_t get_count();
};
