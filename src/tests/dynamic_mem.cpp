#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/parameterized.h>

#include <cstdio>
#include <iostream>
#include <memory>

#include "../../include/dummy_stackable_object.hpp"
#include "../../include/test_allocations.hpp"

class Cont : public Stack {
public:
  StackableObject **stack;
  size_t count;
  Cont(int initial_capacity)
      : count(0), stack(new StackableObject *[initial_capacity]) {}
  ~Cont() { delete[] stack; }

  size_t read_count() const { return this->count; }

  virtual bool push(StackableObject *const new_stackable) override {
    this->stack[this->count] = new_stackable;
    this->count++;
    return true;
  }

  virtual StackableObject *pop() override {
    this->count--;
    return this->stack[this->count];
  }

  virtual size_t get_count() const override { return this->count; }
};

ParameterizedTestParameters(params, cleanup) {
  static criterion::parameters<std::unique_ptr<Cont>> parameters;
  parameters.push_back(std::make_unique<Cont>(2));
  std::cout << "param 0: " << &(*parameters[0]) << "\n";
  return parameters;
}

ParameterizedTest(std::unique_ptr<Cont> &dyn_cont, params, cleanup) {
  std::cout << "*dyn_cont: " << &(*dyn_cont) << "\n";
  int count = dyn_cont->count;
  printf("Parameters: (%d)\n", count);
  count = dyn_cont->read_count();
  printf("Parameters: (%d)\n", count);
  count = dyn_cont->get_count();
  printf("Parameters: (%d)\n", count);
}

