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

static char roti(unsigned int i, char c)
{
    unsigned char chr = c;
    unsigned char letter_offset = (chr | 0x20) - 'a';
    if (letter_offset >= 26) {
        return c;
    }
    return ('A' + ((letter_offset + i) % 26)) | (chr & 0x20);
}

void test_ft_strmapi_basic(void)
{
    char *res = ft_strmapi("abcXYZ", roti);
    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("aceACE", res);
    free(res);
}

void test_ft_strmapi_empty_string(void)
{
    char *res = ft_strmapi("", roti);
    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("", res);
    free(res);
}

void test_ft_strmapi_malloc_failure(void)
{
#ifdef CAN_WRAP_MALLOC
    g_malloc_should_fail = true;
    char *res = ft_strmapi("poulet", roti);
    TEST_ASSERT_NULL(res);
#else
    TEST_IGNORE_MESSAGE("Linker does not support -Wl,--wrap feature");
#endif
}
