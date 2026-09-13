#include "unity.h"
#include "libft.h"

void setUp(void) {}
void tearDown(void) {}

void test_ft_isalpha(void)
{
    for (int i = '\0'; i < 'A'; ++i) {
        TEST_ASSERT_FALSE(ft_isalpha(i));
    }
    for (int i = 'Z' + 1; i < 'a'; ++i) {
        TEST_ASSERT_FALSE(ft_isalpha(i));
    }
    for (int i = 'z' + 1; i <= '\x7f'; ++i) {
        TEST_ASSERT_FALSE(ft_isalpha(i));
    }
    for (int i = 'A'; i <= 'Z'; ++i) {
        TEST_ASSERT_TRUE(ft_isalpha(i));
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        TEST_ASSERT_TRUE(ft_isalpha(i));
    }
    TEST_ASSERT_FALSE(ft_isalpha(EOF));
}
