#include "libft.h"
#include "unity.h"

void setUp(void) {}
void tearDown(void) {}

void test_ft_strlen_basic(void)
{
    TEST_ASSERT_EQUAL_size_t(5, ft_strlen("Shrek"));
}

void test_ft_strlen_empty_str(void)
{
    TEST_ASSERT_EQUAL_size_t(0, ft_strlen(""));
}
