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

void test_ft_lstnew_basic(void)
{
    char *data = "node_data";
    t_list *node = ft_lstnew(data);

    TEST_ASSERT_NOT_NULL(node);
    TEST_ASSERT_EQUAL_PTR(data, node->content);
    TEST_ASSERT_NULL(node->next);

    free(node);
}

void test_ft_lstnew_null_content(void)
{
    t_list *node = ft_lstnew(NULL);

    TEST_ASSERT_NOT_NULL(node);
    TEST_ASSERT_NULL(node->content);
    TEST_ASSERT_NULL(node->next);

    free(node);
}

void test_ft_lstnew_malloc_fail(void)
{
    malloc_mock_failure(true);
    
    t_list *node = ft_lstnew("AARRGGHH");

    TEST_ASSERT_NULL(node);
}
