#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/parameterized.h>

#include <cstdio>

#include "../../include/dummy_stackable_object.hpp"
#include "../../include/dynamic_mem_stack.hpp"
#include "../../include/dynamic_mem_stack_resizeable.hpp"
#include "../../include/fixed_array_stack.hpp"

#define TEST_F(F, S, N, I, ...)                                                \
    Test(S, I##__##N) {                                                        \
        Stack *param = static_cast<Stack *>(new I(__VA_ARGS__));               \
        F(param);                                                              \
        delete param;                                                          \
    }

#define FOR_IMPLEMENTATIONS(F, S, N)                                           \
    TEST_F(F, S, N, FixedArrayStack)                                           \
    TEST_F(F, S, N, DynamicMemStack)                                           \
    TEST_F(F, S, N, DynamicMemStackResizeable, 10)

#define FOR_IMPLEMENTATIONS_FIXED_SIZE(F, S, N)                                \
    TEST_F(F, S, N, FixedArrayStack)                                           \
    TEST_F(F, S, N, DynamicMemStack)

void test_get_count(Stack *stack) {
    cr_assert_eq(stack->get_count(), 0);
    DummyStackableObject obj;
    stack->push(&obj);
    cr_assert_eq(stack->get_count(), 1);
    stack->push(&obj);
    cr_assert_eq(stack->get_count(), 2);
    stack->push(&obj);
    cr_assert_eq(stack->get_count(), 3);
}
FOR_IMPLEMENTATIONS(test_get_count, stack_interface_test, get_count)

void test_push(Stack *stack) {
    DummyStackableObject obj;
    cr_assert(stack->push(&obj));
    cr_assert(stack->push(&obj));
    cr_assert(stack->push(&obj));
    cr_assert(stack->push(&obj));
    cr_assert(stack->push(&obj));
}
FOR_IMPLEMENTATIONS(test_push, stack_interface_test, push)

void test_pop(Stack *stack) {
    DummyStackableObject obj1;
    cr_assert(stack->push(&obj1));
    DummyStackableObject obj2;
    cr_assert(stack->push(&obj2));
    DummyStackableObject obj3;
    cr_assert(stack->push(&obj3));
    cr_assert_eq(&obj3, stack->pop());
    cr_assert_eq(&obj2, stack->pop());
    cr_assert_eq(&obj1, stack->pop());
    cr_assert_eq(nullptr, stack->pop());
}
FOR_IMPLEMENTATIONS(test_pop, stack_interface_test, pop)

void test_fixed_push(Stack *stack) {
    DummyStackableObject obj;
    cr_assert(stack->push(&obj));
    cr_assert(stack->push(&obj));
    cr_assert(stack->push(&obj));
    cr_assert(stack->push(&obj));
    cr_assert(stack->push(&obj));
    cr_assert(stack->push(&obj));
    cr_assert(stack->push(&obj));
    cr_assert(stack->push(&obj));
    cr_assert(stack->push(&obj));
    cr_assert(stack->push(&obj));
    cr_assert(!stack->push(&obj));
}
FOR_IMPLEMENTATIONS_FIXED_SIZE(test_fixed_push, stack_interface_test,
                               fixed_push)
