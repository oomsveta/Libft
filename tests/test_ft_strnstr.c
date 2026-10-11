#include "libft.h"
#include "unity.h"

void setUp(void) {}
void tearDown(void) {}

void test_ft_strnstr_basic(void)
{
    const char *to_scan = "Somebody once told me";
    const char *to_find = "once";
    char *res = ft_strnstr(to_scan, to_find, 21);

    TEST_ASSERT_EQUAL_PTR(to_scan + 9, res);
}

void test_ft_strnstr_empty_needle(void)
{
    const char *to_scan = "the world is gonna roll me";
    const char *to_find = "";
    char *res = ft_strnstr(to_scan, to_find, 26);

    TEST_ASSERT_EQUAL_PTR(to_scan, res);
}

void test_ft_strnstr_not_found(void)
{
    const char *to_scan = "I ain't the sharpest tool in the shed";
    const char *to_find = "stool";
    char *res = ft_strnstr(to_scan, to_find, 37);

    TEST_ASSERT_NULL(res);
}

void test_ft_strnstr_len_cutoff(void)
{
    const char *to_scan = "she was looking kind of dumb";
    const char *to_find = "dumb";
    
    char *res = ft_strnstr(to_scan, to_find, 24);

    TEST_ASSERT_NULL(res);
}

void test_ft_strnstr_zero_len(void)
{
    const char *to_scan = "with her finger and her thumb";
    const char *to_find = "with";
    char *res = ft_strnstr(to_scan, to_find, 0);

    TEST_ASSERT_NULL(res);
}

void test_ft_strnstr_match_at_start(void)
{
    const char *to_scan = "in the shape of an L on her forehead";
    const char *to_find = "in the";
    char *res = ft_strnstr(to_scan, to_find, 6);

    TEST_ASSERT_EQUAL_PTR(to_scan, res);
}

void test_ft_strnstr_bigger_needle(void)
{
    const char *to_scan = "Well";
    const char *to_find = "Well, the years start coming and they don't stop coming";
    char *res = ft_strnstr(to_scan, to_find, 4);

    TEST_ASSERT_NULL(res);
}

void test_ft_strnstr_empty_haystack(void)
{
    const char *to_scan = "";
    const char *to_find = "Fed to the rules and I hit the ground running";
    char *res = ft_strnstr(to_scan, to_find, 45);

    TEST_ASSERT_NULL(res);
}

void test_ft_strnstr_empty_both(void)
{
    const char *to_scan = "";
    const char *to_find = "";
    char *res = ft_strnstr(to_scan, to_find, 42);

    TEST_ASSERT_EQUAL_PTR(to_scan, res);
}
