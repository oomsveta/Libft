#include "unity.h"
#include "libft.h"
#include <limits.h>
#include <stdio.h>

void setUp(void) {}
void tearDown(void) {}

void test_ft_atoi_base_cases(void)
{
    TEST_ASSERT_EQUAL_INT(10, ft_atoi("10"));
    TEST_ASSERT_EQUAL_INT(10, ft_atoi("+10"));
    TEST_ASSERT_EQUAL_INT(-42, ft_atoi("-42"));
    TEST_ASSERT_EQUAL_INT(0, ft_atoi("-0"));
    TEST_ASSERT_EQUAL_INT(0, ft_atoi("0"));
}

void test_ft_atoi_is_not_piscine_atoi(void)
{
    TEST_ASSERT_EQUAL_INT(0, ft_atoi("--19"));
    TEST_ASSERT_EQUAL_INT(0, ft_atoi("+-42"));
    TEST_ASSERT_EQUAL_INT(0, ft_atoi("++67"));
}

void test_ft_atoi_skips_leading_whitespaces(void)
{
    TEST_ASSERT_EQUAL_INT(-1, ft_atoi(" \t\n\r\v\f-1"));
    TEST_ASSERT_EQUAL_INT(0, ft_atoi(" + 123"));
}

void test_ft_atoi_ignores_trailing_crap(void)
{
    TEST_ASSERT_EQUAL_INT(42, ft_atoi(" 42school"));
    TEST_ASSERT_EQUAL_INT(12, ft_atoi("12 34"));
}

void test_ft_atoi_works_with_empty_inputs(void)
{
    TEST_ASSERT_EQUAL_INT(0, ft_atoi(""));
    TEST_ASSERT_EQUAL_INT(0, ft_atoi("-"));
    TEST_ASSERT_EQUAL_INT(0, ft_atoi("   "));
}

void test_ft_atoi_handles_extrema(void)
{
    char int_min_str[32];
    char int_max_str[32];

    sprintf(int_min_str, "%d", INT_MIN);
    sprintf(int_max_str, "%d", INT_MAX);
    TEST_ASSERT_EQUAL_INT(INT_MIN, ft_atoi(int_min_str));
    TEST_ASSERT_EQUAL_INT(INT_MAX, ft_atoi(int_max_str));
}
