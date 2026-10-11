#include "libft.h"
#include "unity.h"

void setUp(void) {}
void tearDown(void) {}

void test_ft_memcpy_basic(void)
{
    const char src[] = "help";
    char dst[20] = {0};

    void *res = ft_memcpy(dst, src, sizeof src);

    TEST_ASSERT_EQUAL_PTR(dst, res);
    TEST_ASSERT_EQUAL_STRING("help", dst);
}

void test_ft_memcpy_partial_copy(void)
{
    const char src[] = "DOFUS";
    char dst[10] = "XXXXXXXXX";

    ft_memcpy(dst, src, 3);

    TEST_ASSERT_EQUAL_MEMORY("DOFXXXXXX", dst, 9);
}

void test_ft_memcpy_zero_size(void)
{
    const char src[] = "won't be copied";
    char dst[] = "shouldn't be modified";

    void *res = ft_memcpy(dst, src, 0);

    TEST_ASSERT_EQUAL_PTR(dst, res);
    TEST_ASSERT_EQUAL_STRING("shouldn't be modified", dst);
}

void test_ft_memcpy_binary(void)
{
    const unsigned char src[] = {0x00, 0x42, 0xFF, 0x00, 0x12};
    unsigned char dst[5] = {0};

    ft_memcpy(dst, src, sizeof src);

    TEST_ASSERT_EQUAL_MEMORY(src, dst, sizeof src);
}

void test_ft_memcpy_int_array(void)
{
    const int src[5] = {10, -20, 300, 4000, 0};
    int dst[5] = {0};

    ft_memcpy(dst, src, sizeof src);

    TEST_ASSERT_EQUAL_INT_ARRAY(src, dst, 5);
}
