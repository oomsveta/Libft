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

void test_ft_substr_basic(void)
{
    char *res = ft_substr("Zorglub", 3, 4);

    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("glub", res);

    free(res);
}

void test_ft_substr_empty_string(void)
{
    char *res = ft_substr("", 1, 4);

    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("", res);

    free(res);
}


void test_ft_substr_start_beyond_len(void)
{
    // if start index is past the end of the string, it should return an empty string
    char *res = ft_substr("shrek", 10, 5);

    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("", res);

    free(res);
}

void test_ft_substr_max_len_exceeds_rest(void)
{
    // if max_len asks for more characters than are available, it should safely cap at the string's end
    char *res = ft_substr("hello guys", 6, 100);

    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("guys", res);

    free(res);
}

void test_ft_substr_max_len_zero(void)
{
    // requesting 0 length should return an allocated empty string
    char *res = ft_substr("Xipe Totec", 2, 0);

    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("", res);

    free(res);
}

void test_ft_substr_malloc_failure(void)
{
    malloc_mock_failure(true);

    char *res = ft_substr("broken", 0, 4);

    TEST_ASSERT_NULL(res);
}
