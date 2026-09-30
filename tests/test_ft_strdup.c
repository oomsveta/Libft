#include "libft.h"
#include "malloc_mock.h"
#include "unity.h"

void setUp(void)
{
    malloc_mock_reset();
}

void tearDown(void)
{
    malloc_mock_reset();
}

void test_ft_strdup_basic(void)
{
    const char *original = "yo la team";
    char *copy = ft_strdup(original);

    TEST_ASSERT_NOT_NULL(copy);
    TEST_ASSERT_EQUAL_STRING(original, copy);
    TEST_ASSERT_NOT_EQUAL(original, copy);

    free(copy);
}

void test_ft_strdup_empty(void)
{
    const char *original = "";
    char *copy = ft_strdup(original);

    TEST_ASSERT_NOT_NULL(copy);
    TEST_ASSERT_EQUAL_STRING(original, copy);
    TEST_ASSERT_NOT_EQUAL(original, copy);

    free(copy);
}

void test_ft_strdup_malloc_fail(void)
{
    malloc_mock_failure(true);

    char *copy = ft_strdup("tout est broken");

    TEST_ASSERT_NULL(copy);
}
