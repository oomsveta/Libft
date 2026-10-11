#include "libft.h"
#include "unity.h"

void setUp(void) {}
void tearDown(void) {}

void test_ft_strchr_found(void)
{
    const char *str = "boustrophédon";
    char *res = ft_strchr(str, 's');

    TEST_ASSERT_EQUAL_PTR(str + 3, res);
}

void test_ft_strchr_not_found(void)
{
    const char *str = "gwoka";
    char *res = ft_strchr(str, 'z');

    TEST_ASSERT_NULL(res);
}

void test_ft_strchr_first_char(void)
{
    const char *str = "FIRST";
    char *res = ft_strchr(str, 'F');

    TEST_ASSERT_EQUAL_PTR(str, res);
}

void test_ft_strchr_null_byte(void)
{
    const char *str = "bob";
    char *res = ft_strchr(str, '\0');

    TEST_ASSERT_EQUAL_PTR(str + 3, res);
    TEST_ASSERT_EQUAL_CHAR('\0', *res);
}

void test_ft_strchr_empty_found(void)
{
    const char *str = "";
    char *res = ft_strchr(str, '\0');

    TEST_ASSERT_EQUAL_PTR(str, res);
}

void test_ft_strchr_empty_not_found(void)
{
    const char *str = "";
    char *res = ft_strchr(str, 'a');

    TEST_ASSERT_NULL(res);
}

void test_ft_strchr_duplicate(void)
{
    const char *str = "banana";
    char *res = ft_strchr(str, 'a');

    TEST_ASSERT_EQUAL_PTR(str + 1, res);
}

void test_ft_strchr_char_overflow(void)
{
    const char *str = "Shrek";
    // 357 % 256 = 'e'
    char *res = ft_strchr(str, 357);

    TEST_ASSERT_EQUAL_PTR(str + 3, res);
}
