#include "libft.h"
#include "malloc_mock.h"
#include "unity.h"
#include <stdlib.h>

void setUp(void)
{
    malloc_mock_reset();
}

void tearDown(void)
{
    malloc_mock_reset();
}

void test_ft_strtrim_basic(void)
{
    char *res = ft_strtrim("  PUTAIN   ", " ");
    
    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("PUTAIN", res);
    free(res);
}

void test_ft_strtrim_multiple_chars_in_set(void)
{
    char *res = ft_strtrim("--xX-Shrek-Xx--", "xX-");

    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("Shrek", res);
    free(res);
}

void test_ft_strtrim_nothing_to_trim(void)
{
    const char *original = "clone me";
    char *res = ft_strtrim(original, "trash");

    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("clone me", res);
    TEST_ASSERT_NOT_EQUAL_PTR(original, res);
    free(res);
}

void test_ft_strtrim_all_trimmed(void)
{
    char *res = ft_strtrim("all in set", "al inset");

    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("", res);
    free(res);
}

void test_ft_strtrim_empty(void)
{
    char *res = ft_strtrim("", "hey");

    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("", res);
    free(res);
}

void test_ft_strtrim_empty_set(void)
{
    char *res = ft_strtrim("babafigue", "");

    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("babafigue", res);
    free(res);
}
