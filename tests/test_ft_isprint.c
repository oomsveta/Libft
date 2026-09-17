#include "unity.h"
#include "libft.h"

void setUp(void) {}
void tearDown(void) {}

void test_ft_isprint_expected_true(void)
{
    for (int i = ' '; i < '\x7f'; ++i) {
        TEST_ASSERT_TRUE(ft_isprint(i));
    }
}

void test_ft_isprint_expected_false(void)
{
    for (int i = '\0'; i < ' '; ++i) {
        TEST_ASSERT_FALSE(ft_isprint(i));
    }
    TEST_ASSERT_FALSE(ft_isprint('\x7f'));
}

void test_ft_isprint_returns_false_for_eof(void)
{
    TEST_ASSERT_FALSE(ft_isprint(EOF));
}
