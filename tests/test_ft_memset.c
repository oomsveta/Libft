#include "libft.h"
#include "unity.h"

void setUp(void) {}
void tearDown(void) {}

void test_ft_memset_basic(void)
{
    char buffer[] = "AAAAAAAAAA";

    void *res = ft_memset(buffer, 'x', 3);

    TEST_ASSERT_EQUAL_PTR(buffer, res);
    TEST_ASSERT_EQUAL_MEMORY("xxxAAAAAAA", buffer, sizeof buffer);
}

void test_ft_memset_bzero(void)
{
    char buffer[] = "minecraft";

    ft_memset(buffer, 0, sizeof buffer);

    const char expected[sizeof buffer] = {0};
    TEST_ASSERT_EQUAL_MEMORY(expected, buffer, sizeof buffer);
}

void test_ft_memset_zero_size(void)
{
    char buffer[] = "shouldn't budge";

    void *res = ft_memset(buffer, 'Z', 0);

    TEST_ASSERT_EQUAL_PTR(buffer, res);
    TEST_ASSERT_EQUAL_STRING("shouldn't budge", buffer);
}

void test_ft_memset_overflow(void)
{
    char buffer[4] = {0};

    // 357 % 256 = 'e'
    ft_memset(buffer, 357, 4);

    TEST_ASSERT_EQUAL_MEMORY("eeee", buffer, 4);
}

void test_ft_memset_negative(void)
{
    unsigned char buffer[4] = {0};

    ft_memset(buffer, -1, 4);

    const unsigned char expected[4] = {0xFF, 0xFF, 0xFF, 0xFF};
    TEST_ASSERT_EQUAL_MEMORY(expected, buffer, 4);
}

void test_ft_memset_int_array_zero(void)
{
    int arr[4] = {10, 20, 30, 40};

    ft_memset(arr, 0, sizeof arr);

    const int expected[4] = {0, 0, 0, 0};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, arr, 4);
}
