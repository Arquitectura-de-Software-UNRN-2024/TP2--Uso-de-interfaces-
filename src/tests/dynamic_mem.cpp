#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

#include "../../include/dynamic_mem_stack.hpp"

Test(get_count__push, test) {
	DynamicMemStack stack(3);
	cr_assert_eq(stack.get_count(), 0);
}

