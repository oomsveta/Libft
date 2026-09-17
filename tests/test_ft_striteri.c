#include "unity.h"
#include "libft.h"
#include <string.h>

static char buffer[64];

void setUp(void)
{
    memset(buffer, 'x', sizeof buffer);
}

void tearDown(void) {}

static void roti(unsigned int i, char *c)
{
    unsigned char chr = *c;
    unsigned char letter_offset = (chr | 0x20) - 'a';
    if (letter_offset >= 26) {
        return;
    }
    *c = ('A' + ((letter_offset + i) % 26)) | (chr & 0x20);
}

void test_ft_striteri_basic(void)
{
    strcpy(buffer, "abcXYZ");
    ft_striteri(buffer, roti);
    TEST_ASSERT_EQUAL_STRING("aceACE", buffer);
}

void test_ft_striteri_empty_string(void)
{
    strcpy(buffer, "");
    ft_striteri(buffer, roti);
    TEST_ASSERT_EQUAL_STRING("", buffer);
    TEST_ASSERT_EQUAL_CHAR_MESSAGE('x', buffer[1], "buffer modified on empty string");
}
