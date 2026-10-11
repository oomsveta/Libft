#include "libft.h"
#include "unity.h"

void setUp(void) {}
void tearDown(void) {}

void test_ft_strrchr_duplicate(void)
{
    const char *str = "banana";
    char *res = ft_strrchr(str, 'a');

    TEST_ASSERT_EQUAL_PTR(str + 5, res);
}

void test_ft_strrchr_not_found(void)
{
    const char *str = "crabe";
    char *res = ft_strrchr(str, 'z');

    TEST_ASSERT_NULL(res);
}

void test_ft_strrchr_first_char(void)
{
    const char *str = "yo la team";
    char *res = ft_strrchr(str, 'y');

    TEST_ASSERT_EQUAL_PTR(str, res);
}

void test_ft_strrchr_null_byte(void)
{
    const char *str = "shrek";
    char *res = ft_strrchr(str, '\0');

    TEST_ASSERT_EQUAL_PTR(str + 5, res);
    TEST_ASSERT_EQUAL_CHAR('\0', *res);
}

void test_ft_strrchr_empty_found(void)
{
    const char *str = "";
    char *res = ft_strrchr(str, '\0');

    TEST_ASSERT_EQUAL_PTR(str, res);
}

void test_ft_strrchr_empty_not_found(void)
{
    const char *str = "";
    char *res = ft_strrchr(str, 'a');

    TEST_ASSERT_NULL(res);
}

void test_ft_strrchr_overflow(void)
{
    const char *str = "Shrek";
    // 370 % 256 = 'r'
    char *res = ft_strrchr(str, 370);

    TEST_ASSERT_EQUAL_PTR(str + 2, res);
}
