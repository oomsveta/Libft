#include "libft.h"
#include "unity.h"
#include <limits.h>

void setUp(void) {}
void tearDown(void) {}

void test_ft_isascii_returns_true_for_ascii_range(void)
{
    for (int i = '0'; i <= '\x7f'; ++i) {
        TEST_ASSERT_TRUE(ft_isascii(i));
    }
}

void test_ft_isascii_returns_false_outside_ascii_range(void)
{
    for (int i = '\x7f' + 1; i <= UCHAR_MAX; ++i) {
        TEST_ASSERT_FALSE(ft_isascii(i));
    }
}

void test_ft_isascii_returns_false_for_eof(void)
{
    TEST_ASSERT_FALSE(ft_isascii(EOF));
}
