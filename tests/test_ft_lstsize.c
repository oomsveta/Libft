#include "libft.h"
#include "unity.h"
#include <stddef.h> // provides NULL

void setUp(void) {}
void tearDown(void) {}

void test_ft_lstsize_null(void)
{
    TEST_ASSERT_EQUAL_INT(0, ft_lstsize(NULL));
}

void test_ft_lstsize_one_element(void)
{
    t_list elem = { .content = "head", .next = NULL };

    TEST_ASSERT_EQUAL_INT(1, ft_lstsize(&elem));
}

void test_ft_lstsize_multiple_elements(void)
{
    t_list node3 = { .content = "three", .next = NULL };
    t_list node2 = { .content = "two",   .next = &node3 };
    t_list node1 = { .content = "one",   .next = &node2 };

    TEST_ASSERT_EQUAL_INT(3, ft_lstsize(&node1));
}
