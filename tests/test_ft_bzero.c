#include "libft.h"
#include "unity.h"
#include <string.h>

static char buffer[64];

void setUp(void)
{
    memset(buffer, 'x', sizeof buffer);
}

void tearDown(void) {}

void test_ft_bzero_basic(void)
{
    const char expected[10] = {0};
    ft_bzero(buffer, 10);
    TEST_ASSERT_EQUAL_MEMORY(expected, buffer, 10);
    TEST_ASSERT_EQUAL_CHAR_MESSAGE('x', buffer[10], "buffer overflow");
}

void test_ft_bzero_zero_size(void)
{
    ft_bzero(buffer, 0);
    TEST_ASSERT_EQUAL_CHAR_MESSAGE('x', buffer[0], "buffer modified when n = 0");
}

void test_ft_bzero_single_byte(void)
{
    ft_bzero(buffer, 1);
    TEST_ASSERT_EQUAL_CHAR(0, buffer[0]);
    TEST_ASSERT_EQUAL_CHAR_MESSAGE('x', buffer[1], "buffer overflow");
}

void test_ft_bzero_preserves_surrounding_bytes(void)
{
    const char expected[10] = {0};
    ft_bzero(buffer + 5, 10);
    TEST_ASSERT_EQUAL_CHAR('x', buffer[4]);
    TEST_ASSERT_EQUAL_MEMORY(expected, buffer + 5, 10);
    TEST_ASSERT_EQUAL_CHAR_MESSAGE('x', buffer[15], "buffer overflow");
}
