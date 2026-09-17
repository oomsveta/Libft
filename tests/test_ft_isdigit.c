#include "unity.h"
#include "libft.h"

void setUp(void) {}
void tearDown(void) {}

void test_ft_isdigit_returns_true_for_digits(void)
{
    for (int i = '0'; i <= '9'; ++i) {
        TEST_ASSERT_TRUE(ft_isdigit(i));
    }
}

void test_ft_isdigit_returns_false_for_non_digit(void)
{
    for (int i = '\0'; i < '0'; ++i) {
        TEST_ASSERT_FALSE(ft_isdigit(i));
    }
    for (int i = '9' + 1; i <= '\x7f'; ++i) {
        TEST_ASSERT_FALSE(ft_isdigit(i));
    }
}

void test_ft_isdigit_returns_false_for_eof(void)
{
    TEST_ASSERT_FALSE(ft_isdigit(EOF));
}
