#include "libft.h"
#include "unity.h"
#include <string.h>

static char buffer[64];

void setUp(void)
{
    memset(buffer, 'x', sizeof buffer);
}

void tearDown(void) {}

void test_strlcpy_bigger_dest(void)
{
    const char *src = "Shrek";
    const size_t src_length = strlen(src);
    const size_t res = ft_strlcpy(buffer, src, sizeof buffer - 1);
    TEST_ASSERT_EQUAL_size_t(res, src_length);
    TEST_ASSERT_EQUAL_STRING(src, buffer);
    TEST_ASSERT_EQUAL_CHAR_MESSAGE('x', buffer[src_length + 1], "buffer overflow");
}

void test_strlcpy_dest_too_small(void)
{
    const char *src = "pseudopseudohypoparathyroidism";
    const size_t res = ft_strlcpy(buffer, src, 7);
    TEST_ASSERT_EQUAL_size_t(strlen(src), res);
    TEST_ASSERT_EQUAL_STRING("pseudo", buffer);
    TEST_ASSERT_EQUAL_CHAR_MESSAGE('x', buffer[7], "buffer overflow");
}

void test_strlcpy_exact_fit(void)
{
    const char *src = "feur";
    const size_t src_length = strlen(src);
    const size_t res = ft_strlcpy(buffer, src, src_length + 1);
    TEST_ASSERT_EQUAL_size_t(src_length, res);
    TEST_ASSERT_EQUAL_STRING(src, buffer);
    TEST_ASSERT_EQUAL_CHAR_MESSAGE('x', buffer[src_length + 1], "buffer overflow");
}

void test_strlcpy_dstsize_0(void)
{
    const char *src = "Morshu RTX";
    const size_t res = ft_strlcpy(buffer, src, 0);
    TEST_ASSERT_EQUAL_size_t(strlen(src), res);
    TEST_ASSERT_EQUAL_CHAR_MESSAGE('x', buffer[0], "buffer overflow");
}

void test_strlcpy_dstsize_1(void)
{
    const char *src = "dofus.com";
    const size_t res = ft_strlcpy(buffer, src, 1);
    TEST_ASSERT_EQUAL_size_t(strlen(src), res);
    TEST_ASSERT_EQUAL_STRING("", buffer);
    TEST_ASSERT_EQUAL_CHAR_MESSAGE('x', buffer[1], "buffer overflow");
}

void test_strlcpy_truncated_end(void)
{
    const char *src = "Xanto";
    const size_t src_length = strlen(src);
    const size_t res = ft_strlcpy(buffer, src, src_length);
    TEST_ASSERT_EQUAL_size_t(res, src_length);
    TEST_ASSERT_EQUAL_STRING("Xant", buffer);
    TEST_ASSERT_EQUAL_CHAR_MESSAGE('x', buffer[src_length], "buffer overflow");
}

void test_strlcpy_empty_src(void)
{
    const char *src = "";
    const size_t res = ft_strlcpy(buffer, src, 1);
    TEST_ASSERT_EQUAL_size_t(res, 0);
    TEST_ASSERT_EQUAL_STRING("", buffer);
}
