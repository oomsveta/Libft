#include "libft.h"
#include "unity.h"

void setUp(void) {}
void tearDown(void) {}

void test_ft_memmove_basic(void)
{
    const char src[] = "tintin au tibet";
    char dst[20] = {0};

    void *res = ft_memmove(dst, src, sizeof src);

    TEST_ASSERT_EQUAL_PTR(dst, res);
    TEST_ASSERT_EQUAL_STRING("tintin au tibet", dst);
}

void test_ft_memmove_overlap_dst_after_src(void)
{
    char str[] = "0123456789";

    void *res = ft_memmove(str + 2, str, 5);

    TEST_ASSERT_EQUAL_PTR(str + 2, res);
    TEST_ASSERT_EQUAL_STRING("0101234789", str);
}

void test_ft_memmove_overlap_dst_before_src(void)
{
    char str[] = "0123456789";

    void *res = ft_memmove(str, str + 2, 5);

    TEST_ASSERT_EQUAL_PTR(str, res);
    TEST_ASSERT_EQUAL_STRING("2345656789", str);
}

void test_ft_memmove_same_object(void)
{
    char str[] = "No change";

    void *res = ft_memmove(str, str, 9);

    TEST_ASSERT_EQUAL_PTR(str, res);
    TEST_ASSERT_EQUAL_STRING("No change", str);
}

void test_ft_memmove_zero_size(void)
{
    char str[] = "shouldn't budge";

    void *res = ft_memmove(str, str + 2, 0);

    TEST_ASSERT_EQUAL_PTR(str, res);
    TEST_ASSERT_EQUAL_STRING("shouldn't budge", str);
}

void test_ft_memmove_binary(void)
{
    unsigned char buffer[] = {0xAA, 0x00, 0xBB, 0xCC, 0x00, 0xDD};

    ft_memmove(buffer + 2, buffer, 4);

    const unsigned char expected[] = {0xAA, 0x00, 0xAA, 0x00, 0xBB, 0xCC};
    TEST_ASSERT_EQUAL_MEMORY(expected, buffer, sizeof buffer);
}

void test_ft_memmove_int_array_overlap(void)
{
    int arr[6] = {1, 2, 3, 4, 5, 6};

    ft_memmove(&arr[1], &arr[0], 4 * sizeof(int));

    const int expected[6] = {1, 1, 2, 3, 4, 6};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, arr, 6);
}
