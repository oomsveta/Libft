#include "unity.h"
#include "libft.h"

void setUp(void) {}
void tearDown(void) {}

void test_ft_isalnum_returns_true_for_digits(void)
{
    for (int i = '0'; i <= '9'; ++i) {
        TEST_ASSERT_TRUE(ft_isalnum(i));
    }
}

void test_ft_isalnum_returns_true_for_letters(void)
{
    for (int i = 'A'; i <= 'Z'; ++i) {
        TEST_ASSERT_TRUE(ft_isalnum(i));
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        TEST_ASSERT_TRUE(ft_isalnum(i));
    }
}

void test_ft_isalnum_returns_false_for_eof(void)
{
    TEST_ASSERT_FALSE(ft_isalnum(EOF));
}

void test_ft_isalnum_returns_false_for_non_alphanum(void)
{
    for (int i = '\0'; i < '0'; ++i) {
        TEST_ASSERT_FALSE(ft_isalnum(i));
    }
    for (int i = '9' + 1; i < 'A'; ++i) {
        TEST_ASSERT_FALSE(ft_isalnum(i));
    } 
    for (int i = 'Z' + 1; i < 'a'; ++i) {
        TEST_ASSERT_FALSE(ft_isalnum(i));
    }
    for (int i = 'z' + 1; i <= '\x7f'; ++i) {
        TEST_ASSERT_FALSE(ft_isalnum(i));
    }
}
