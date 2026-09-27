#include "libft.h"
#include "malloc_mock.h"
#include "unity.h"

void setUp(void)
{
    malloc_mock_reset();
}

void tearDown(void)
{
    malloc_mock_reset();
}

void test_ft_strjoin_basic(void)
{
    char *res = ft_strjoin("hello ", "world");
    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("hello world", res);
    free(res);
}

void test_ft_strjoin_empty_left(void)
{
    char *res = ft_strjoin("", "shrek");
    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("shrek", res);
    free(res);
}

void test_ft_strjoin_empty_right(void)
{
    char *res = ft_strjoin("gwonam", "");
    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("gwonam", res);
    free(res);
}

void test_ft_strjoin_both_empty(void)
{
    char *res = ft_strjoin("", "");
    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("", res);
    free(res);
}

void test_ft_strjoin_malloc_failure(void)
{
    malloc_mock_failure(true);
    char *res = ft_strjoin("will", "fail");
    TEST_ASSERT_NULL(res);
}
