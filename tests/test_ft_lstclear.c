#include "libft.h"
#include "unity.h"
#include <stdlib.h>

static size_t g_delete_fn_call_count = 0;

void setUp(void)
{
    g_delete_fn_call_count = 0;
}

void tearDown(void) {}

static void dummy_del(void *content)
{
    (void)content;
    g_delete_fn_call_count += 1;
}

static t_list *create_node(void *content)
{
    t_list *node = malloc(sizeof *node);
    if (!node) {
        return NULL;
    }
    *node = (t_list){.content=content, .next=NULL};
    return node;
}

void test_ft_lstclear_multiple_nodes(void)
{
    t_list *head = create_node("Philippe");
    head->next = create_node("Albert");
    head->next->next = create_node("Léopold");

    ft_lstclear(&head, dummy_del);

    TEST_ASSERT_NULL(head);
    TEST_ASSERT_EQUAL_size_t(3, g_delete_fn_call_count);
}

void test_ft_lstclear_single_node(void)
{
    t_list *head = create_node("mangon");

    ft_lstclear(&head, dummy_del);

    TEST_ASSERT_NULL(head);
    TEST_ASSERT_EQUAL_size_t(1, g_delete_fn_call_count);
}

void test_ft_lstclear_empty_list(void)
{
    t_list *head = NULL;

    ft_lstclear(&head, dummy_del);

    TEST_ASSERT_NULL(head);
    TEST_ASSERT_EQUAL_size_t(0, g_delete_fn_call_count);
}
