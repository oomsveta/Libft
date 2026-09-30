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

static void free_all(char **split)
{
    if (!split) {
        return;
    }
    for (size_t i = 0; split[i] != NULL; ++i) {
        free(split[i]);
    }
    free(split);
}

void test_ft_split_basic(void)
{
    char **res = ft_split("minecraft wii u", ' ');

    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("minecraft", res[0]);
    TEST_ASSERT_EQUAL_STRING("wii", res[1]);
    TEST_ASSERT_EQUAL_STRING("u", res[2]);
    TEST_ASSERT_NULL(res[3]);

    free_all(res);
}

void test_ft_split_empty_string(void)
{
    char **res = ft_split("", ' ');

    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_NULL(res[0]);

    free_all(res);
}

void test_ft_split_malloc_fail_array(void)
{
    malloc_mock_fail_after(1);
    char **res = ft_split("💣💥", ' ');

    TEST_ASSERT_NULL(res);
}

void test_ft_split_malloc_fail_first_word(void)
{
    // call 1: the array of pointers
    // call 2: The first word ("I") -> should fail
    malloc_mock_fail_after(2);
    char **res = ft_split("I am Error", ' ');

    TEST_ASSERT_NULL(res);
}

void test_ft_split_malloc_fail_second_word(void)
{
    // call 1: the array of pointers
    // call 2: "Macron..."
    // call 3: "EXPLOSION!!" -> should fail
    malloc_mock_fail_after(3);
    char **res = ft_split("Macron... EXPLOSION!!", ' ');

    TEST_ASSERT_NULL(res);
}

void test_ft_split_separators_at_beginning(void)
{
    char **res = ft_split("--42-belgium", '-');

    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("42", res[0]);
    TEST_ASSERT_EQUAL_STRING("belgium", res[1]);
    TEST_ASSERT_NULL(res[2]);

    free_all(res);
}

void test_ft_split_separators_at_end(void)
{
    char **res = ft_split("grand+gousier++", '+');

    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("grand", res[0]);
    TEST_ASSERT_EQUAL_STRING("gousier", res[1]);
    TEST_ASSERT_NULL(res[2]);

    free_all(res);
}

void test_ft_split_multiple_consecutive_separators(void)
{
    char **res = ft_split("hello   world", ' ');

    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("hello", res[0]);
    TEST_ASSERT_EQUAL_STRING("world", res[1]);
    TEST_ASSERT_NULL(res[2]);

    free_all(res);
}

void test_ft_split_all_combined(void)
{
    char **res = ft_split("   hello   world   ", ' ');

    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("hello", res[0]);
    TEST_ASSERT_EQUAL_STRING("world", res[1]);
    TEST_ASSERT_NULL(res[2]);

    free_all(res);
}

void test_ft_split_only_separators(void)
{
    char **res = ft_split("     ", ' ');

    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_NULL(res[0]);

    free_all(res);
}
