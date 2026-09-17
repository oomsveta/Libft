#include "libft.h"
#include "unity.h"
#include <string.h>

static char buffer[64];

void setUp(void)
{
    memset(buffer, 'x', sizeof buffer);
}

void tearDown(void) {}

// return value = min(size, len(dest)) + len(src)

void test_ft_strlcat_exact_fit(void)
{
    strcpy(buffer, "con");
    const size_t res = ft_strlcat(buffer, "cat", 7);
    TEST_ASSERT_EQUAL_size_t(6, res);
    TEST_ASSERT_EQUAL_STRING("concat", buffer);
    TEST_ASSERT_EQUAL_CHAR_MESSAGE('x', buffer[7], "buffer overflow");
}

void test_ft_strlcat_dstsize_smaller_than_dst_len(void)
{
    strcpy(buffer, "Gargamel");
    const size_t res = ft_strlcat(buffer, "Grossbouf", 3);
    TEST_ASSERT_EQUAL_size_t(12, res); // size + len("Grossbouf")
    TEST_ASSERT_EQUAL_STRING("Gargamel", buffer);
}

void test_ft_strlcat_dstsize_equals_dst_len(void)
{
    strcpy(buffer, "voiture");
    const size_t res = ft_strlcat(buffer, "TG", 7);
    TEST_ASSERT_EQUAL_size_t(9, res); // len("voiture") + len("TG")
    TEST_ASSERT_EQUAL_STRING("voiture", buffer);
}

void test_ft_strlcat_src_truncated(void)
{
    strcpy(buffer, "swamp");
    const size_t res = ft_strlcat(buffer, "edition", 8);
    TEST_ASSERT_EQUAL_size_t(12, res); // len("swamp") + len("edition")
    TEST_ASSERT_EQUAL_STRING("swamped", buffer);
}

void test_ft_strlcat_dstsize_0(void)
{
    strcpy(buffer, "Mario");
    const size_t res = ft_strlcat(buffer, "Luigi", 0);
    TEST_ASSERT_EQUAL_size_t(5, res); // size + len("Luigi")
    TEST_ASSERT_EQUAL_STRING("Mario", buffer);
}

// dstsize = len(dst) + 1 (room ONLY for the null-terminator)
void test_ft_strlcat_room_for_null_only(void)
{
    strcpy(buffer, "tiramisu");
    const size_t res = ft_strlcat(buffer, "speculoos", 9);
    TEST_ASSERT_EQUAL_size_t(17, res); // len("tiramisu") + len("speculoos")
    TEST_ASSERT_EQUAL_STRING("tiramisu", buffer);
    TEST_ASSERT_EQUAL_CHAR_MESSAGE('x', buffer[9], "buffer overflow");
}

void test_ft_strlcat_empty_src(void)
{
    strcpy(buffer, "wampanoag");
    const size_t res = ft_strlcat(buffer, "", sizeof buffer - 1);
    TEST_ASSERT_EQUAL_size_t(9, res); // len("wampanoag") + len("")
    TEST_ASSERT_EQUAL_STRING("wampanoag", buffer);
}

void test_ft_strlcat_empty_dst(void)
{
    strcpy(buffer, "");
    const size_t res = ft_strlcat(buffer, "stroopwafel", sizeof buffer - 1);
    TEST_ASSERT_EQUAL_size_t(11, res); // len("") + len("stroopwafel")
    TEST_ASSERT_EQUAL_STRING("stroopwafel", buffer);
}

void test_ft_strlcat_no_null_in_dstsize(void)
{
    const size_t res = ft_strlcat(buffer, "Shrek", 5);
    TEST_ASSERT_EQUAL_size_t(10, res); // size + len("Shrek")
    TEST_ASSERT_EQUAL_CHAR_MESSAGE('x', buffer[0], "buffer must remain untouched");
}
