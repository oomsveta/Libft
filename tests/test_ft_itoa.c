#include "libft.h"
#include "unity.h"
#include <limits.h>
#include <stdlib.h>
#ifdef CAN_WRAP_MALLOC
#include <stdbool.h>

static bool g_malloc_should_fail = false;

extern void *__real_malloc(size_t size);

void *__wrap_malloc(size_t size)
{
    if (g_malloc_should_fail) {
        return NULL;
    }
    return __real_malloc(size);
}
#endif

void setUp(void)
{
#ifdef CAN_WRAP_MALLOC
    g_malloc_should_fail = false;
#endif
}
void tearDown(void)
{
#ifdef CAN_WRAP_MALLOC
    g_malloc_should_fail = false;
#endif
}

void test_ft_itoa_zero(void)
{
    char *res = ft_itoa(0);
    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("0", res);
    free(res);
}

void test_ft_itoa_positive_single_digit(void)
{
    char *res = ft_itoa(7);
    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("7", res);
    free(res);
}

void test_ft_itoa_positive_multi_digit(void)
{
    char *res = ft_itoa(1234567890);
    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("1234567890", res);
    free(res);
}

void test_ft_itoa_negative_single_digit(void)
{
    char *res = ft_itoa(-8);
    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("-8", res);
    free(res);
}

void test_ft_itoa_negative_multi_digit(void)
{
    char *res = ft_itoa(-42);
    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("-42", res);
    free(res);
}

void test_ft_itoa_int_max(void)
{
    char expected[32];
    sprintf(expected, "%d", INT_MAX);
    char *res = ft_itoa(INT_MAX);
    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING(expected, res);
    free(res);
}

void test_ft_itoa_int_min(void)
{
    char expected[32];
    sprintf(expected, "%d", INT_MIN);
    char *res = ft_itoa(INT_MIN);
    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING(expected, res);
    free(res);
}

void test_ft_itoa_malloc_failure(void)
{
#ifdef CAN_WRAP_MALLOC
    g_malloc_should_fail = true;
    char *res = ft_itoa(1337);
    TEST_ASSERT_NULL(res);
#else
    TEST_IGNORE_MESSAGE("Linker does not support -Wl,--wrap feature");
#endif
}
