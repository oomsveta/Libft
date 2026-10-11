#include "libft.h"
#include "unity.h"
#include <stddef.h>

void setUp(void) {}
void tearDown(void) {}

void test_ft_memchr_found(void)
{
    const char test_case[] = "bibimbap";
    void *res = ft_memchr(test_case, 'a', sizeof(test_case));

    TEST_ASSERT_EQUAL_PTR(test_case + 6, res);
}

void test_ft_memchr_not_found(void)
{
    const char test_case[] = "Shrek";
    void *res = ft_memchr(test_case, 'x', sizeof(test_case));

    TEST_ASSERT_NULL(res);
}

void test_ft_memchr_first_byte(void)
{
    const char test_case[] = "42";
    void *res = ft_memchr(test_case, '4', sizeof(test_case));

    TEST_ASSERT_EQUAL_PTR(test_case, res);
}

void test_ft_memchr_last_byte(void)
{
    const char test_case[] = "swamp";
    void *res = ft_memchr(test_case, 'p', 5);

    TEST_ASSERT_EQUAL_PTR(test_case + 4, res);
}

void test_ft_memchr_match_beyond_n(void)
{
    const char test_case[] = "salut";
    void *res = ft_memchr(test_case, 't', 4);

    TEST_ASSERT_NULL(res);
}

void test_ft_memchr_zero_size(void)
{
    const char test_case[] = "Gwonam";
    void *res = ft_memchr(test_case, 'G', 0);

    TEST_ASSERT_NULL(res);
}

void test_ft_memchr_null_byte(void)
{
    const unsigned char test_case[] = {0x01, 0x02, 0x00, 0x03, 0x04};
    void *res = ft_memchr(test_case, '\0', sizeof(test_case));

    TEST_ASSERT_EQUAL_PTR(test_case + 2, res);
}

void test_ft_memchr_duplicate(void)
{
    const char test_case[] = "banana";
    void *res = ft_memchr(test_case, 'a', 6);

    TEST_ASSERT_EQUAL_PTR(test_case + 1, res);
}

void test_ft_memchr_unsigned_char(void)
{
    const char test_case[] = "hello";
    // 'e' + 256 = 357.
    void *res = ft_memchr(test_case, 357, 5);

    TEST_ASSERT_EQUAL_PTR(test_case + 1, res);
}

void test_ft_memchr_extended_ascii(void)
{
    const unsigned char test_case[] = {0x10, 0x80, 0xFF, 0x7F};

    void *res = ft_memchr(test_case, 0xFF, sizeof(test_case));
    TEST_ASSERT_EQUAL_PTR(test_case + 2, res);

    // (unsigned char)-1 = 0xFF
    res = ft_memchr(test_case, -1, sizeof(test_case));
    TEST_ASSERT_EQUAL_PTR(test_case + 2, res);
}
