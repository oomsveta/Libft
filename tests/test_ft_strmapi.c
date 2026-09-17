#include "libft.h"
#include "unity.h"
#include <stdlib.h>

void setUp(void) {}
void tearDown(void) {}

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
