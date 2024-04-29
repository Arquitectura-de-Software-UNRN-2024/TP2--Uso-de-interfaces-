#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/parameterized.h>

#include <cstdio>
#include <iostream>
#include <memory>

#include "../../include/dummy_stackable_object.hpp"
// #include "../../include/dynamic_mem_stack.hpp"
// #include "../../include/test_allocations.hpp"

/*criterion::parameters<Stack *> gen_test_parameters() {
  criterion::parameters<Stack *> parameters = {
      criterion::new_obj<DynamicMemStack>(3)};
  return parameters;
};*/

/*
#define ParamTest(P, S, N)                                                     \
  ParameterizedTestParameters(S, N) {                                          \
    criterion::parameters<Stack *> parameters = gen_test_parameters();         \
    return parameters;                                                         \
  }                                                                            \
  ParameterizedTest(P, S, N)
  */

// ParamTest(Stack *stack, stack_interface_test, get_count) {

/*ParameterizedTestParameters(stack_interface_test, get_count) {
  static Stack *vals[] = {criterion::new_obj<DynamicMemStack>(3)};
  return cr_make_param_array(Stack *, vals, sizeof(vals) / sizeof(Stack *));
}

ParameterizedTest(Stack **stack, stack_interface_test, get_count) {
  cr_assert_eq((*stack)->get_count(), 0);
  DummyStackableObject obj;
  (*stack)->push(&obj);
  cr_assert_eq((*stack)->get_count(), 1);
  (*stack)->push(&obj);
  cr_assert_eq((*stack)->get_count(), 2);
  (*stack)->push(&obj);
  cr_assert_eq((*stack)->get_count(), 3);
}*/

/*ParamTest(Stack *stack, stack_interface_test, push) {
  DummyStackableObject obj;
  cr_assert(stack->push(&obj));
  cr_assert(stack->push(&obj));
  cr_assert(stack->push(&obj));
  cr_assert(!stack->push(&obj));
}*/

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

/*ParameterizedTestParameters(params, cleanup) {
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
}*/

#define TEST_F(I, F, S, N)                                                     \
  Test(S, N) {                                                                 \
    std::cout << "test\n";                                                     \
    Stack *param = new I;                                                      \
    F(param);                                                                  \
    delete param;                                                              \
  }

#define FOR_IMPLEMENTATIONS(F, S, N) TEST_F(Cont(2), F, S, N)

void test(Stack *dyn_cont) {
  // std::cout << "*dyn_cont: " << &(*dyn_cont) << "\n";
  int count = 2;
  // count = dyn_cont->get_count();
  printf("Parameters: (%d)\n", count);
}

FOR_IMPLEMENTATIONS(test, s, c)
