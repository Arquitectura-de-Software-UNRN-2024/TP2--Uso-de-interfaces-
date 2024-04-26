#include <criterion/alloc.h>
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/parameterized.h>

#include "../../include/dummy_stackable_object.hpp"
#include "../../include/dynamic_mem_stack.hpp"

#include <criterion/new/assert.h>
#include <cstdio>
#include <iostream>

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

struct ParamDyn {
  std::unique_ptr<DynamicMemStack, decltype(criterion::free)> d;
  ParamDyn(DynamicMemStack *d) : d(d, criterion::free) {}
};

static criterion::parameters<ParamDyn> parameters;

ParameterizedTestParameters(params, cleanup) {
  parameters.push_back(ParamDyn(criterion::new_obj<DynamicMemStack>(
      2, criterion::malloc,
      criterion::free)));
  std::cout << "parameters: " << &parameters << "\n";
  std::cout << "parameter 0: " << &(*parameters[0].d) << "\n";
  std::cout << "parameter 0 get_count: " << parameters[0].d->get_count()
            << "\n";
  return parameters;
}

ParameterizedTest(ParamDyn *tup, params, cleanup) {
  std::cout << "tup: " << tup << "\n";
  std::cout << "*tup: " << &(*tup->d) << "\n";
  int a = 2;
  printf("Parameters: (%d)\n", a);
  a = tup->d->get_count();
  printf("Parameters: (%d)\n", a);
  // criterion::delete_obj(tup);
}
