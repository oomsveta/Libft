#include "libft.h"
#include "unity.h"
#include <stdlib.h>

#ifdef CAN_WRAP_MALLOC
#include <stdbool.h>

static bool g_malloc_should_fail = false;

extern void *__real_malloc(size_t size);

void *__wrap_malloc(size_t size)
{
    if (g_malloc_should_fail) {
        return NULL;
    }
    return __real_malloc(size);
}
#endif

void setUp(void)
{
#ifdef CAN_WRAP_MALLOC
    g_malloc_should_fail = false;
#endif
}
void tearDown(void)
{
#ifdef CAN_WRAP_MALLOC
    g_malloc_should_fail = false;
#endif
}

void test_ft_calloc_basic(void)
{
    const size_t count = 10;
    const size_t total_bytes = count * sizeof(int);
    int *ptr = ft_calloc(count, sizeof(int));
    TEST_ASSERT_NOT_NULL(ptr);
    const int expected[10] = {0};
    TEST_ASSERT_EQUAL_MEMORY(expected, ptr, total_bytes);
    free(ptr);
}

void test_ft_calloc_single_byte(void)
{
    char *ptr = ft_calloc(1, 1);
    TEST_ASSERT_NOT_NULL(ptr);
    TEST_ASSERT_EQUAL_CHAR(0, *ptr);
    free(ptr);
}

void test_ft_calloc_zero_count(void)
{
    void *ptr = ft_calloc(0, 10);
    free(ptr);
}

void test_ft_calloc_zero_size(void)
{
    void *ptr = ft_calloc(10, 0);
    free(ptr);
}

void test_ft_calloc_zero_both(void)
{
    void *ptr = ft_calloc(0, 0);
    free(ptr);
}

void test_ft_calloc_overflow(void)
{
    // SIZE_MAX * SIZE_MAX overflows size_t; calloc must fail safely and return NULL
    void *ptr = ft_calloc(SIZE_MAX, SIZE_MAX);
    TEST_ASSERT_NULL(ptr);
}

void test_ft_calloc_large_allocation(void)
{
    const size_t count = 1024;
    const size_t size = 1024;
    unsigned char *ptr = ft_calloc(count, size);
    TEST_ASSERT_NOT_NULL(ptr);
    // Spot-check start, middle, and end bytes
    TEST_ASSERT_EQUAL_UINT8(0, ptr[0]);
    TEST_ASSERT_EQUAL_UINT8(0, ptr[512 * 1024]);
    TEST_ASSERT_EQUAL_UINT8(0, ptr[(count * size) - 1]);
    free(ptr);
}

void test_ft_calloc_malloc_failure(void)
{
#ifdef CAN_WRAP_MALLOC
    g_malloc_should_fail = true;
    char *res = ft_strjoin("will", "fail");
    TEST_ASSERT_NULL(res);
#else
    // Requests ~1 exabyte so that malloc fails.
    // Wrapping malloc is cleaner, but it isn't supported on macOS.
    void *ptr = ft_calloc(1e9, 1e9);
    TEST_ASSERT_NULL(ptr);
#endif
}
