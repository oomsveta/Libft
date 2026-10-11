#include "libft.h"
#include "unity.h"

void setUp(void) {}
void tearDown(void) {}

void test_ft_strncmp_identical(void)
{
    TEST_ASSERT_EQUAL_INT(0, ft_strncmp("vroum", "vroum", 5));
}

void test_ft_strncmp_greater(void)
{
    int res = ft_strncmp("pot", "pod", 3);
    TEST_ASSERT_TRUE(res > 0);
}

void test_ft_strncmp_less(void)
{
    int res = ft_strncmp("abracadabra", "banana", 6);
    TEST_ASSERT_TRUE(res < 0);
}

void test_ft_strncmp_zero_n(void)
{
    TEST_ASSERT_EQUAL_INT(0, ft_strncmp("abc", "xyz", 0));
}

void test_ft_strncmp_n_identical(void)
{
    TEST_ASSERT_EQUAL_INT(0, ft_strncmp("aaabbb", "aaahhh", 3));
}

void test_ft_strncmp_unsigned_char(void)
{
    int res = ft_strncmp("\x80", "Zorglub", 1);
    TEST_ASSERT_TRUE(res > 0);

    res = ft_strncmp("Roblox", "\xFF", 1);
    TEST_ASSERT_TRUE(res < 0);
}
