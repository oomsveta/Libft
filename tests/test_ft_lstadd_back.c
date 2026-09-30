#include "libft.h"
#include "unity.h"
#include <stdlib.h>

void setUp(void) {}
void tearDown(void) {}

static t_list *create_node(void *content)
{
    t_list *node = malloc(sizeof *node);
    if (!node) {
        return NULL;
    }
    *node = (t_list){.content=content, .next=NULL};
    return node;
}

static void free_list(t_list *lst)
{
    t_list *tmp;
    while (lst) {
        tmp = lst->next;
        free(lst);
        lst = tmp;
    }
}

void test_ft_lstadd_back_empty_list(void)
{
    t_list *head = NULL;
    t_list *node = create_node("first");

    ft_lstadd_back(&head, node);

    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_PTR(node, head);
    TEST_ASSERT_EQUAL_STRING("first", head->content);
    TEST_ASSERT_NULL(head->next);

    free_list(head);
}

void test_ft_lstadd_back_single_node(void)
{
    t_list *head = create_node("first");
    t_list *node2 = create_node("second");

    ft_lstadd_back(&head, node2);

    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_STRING("first", head->content);

    TEST_ASSERT_NOT_NULL(head->next);
    TEST_ASSERT_EQUAL_PTR(node2, head->next);
    TEST_ASSERT_EQUAL_STRING("second", head->next->content);
    TEST_ASSERT_NULL(head->next->next);

    free_list(head);
}

void test_ft_lstadd_back_multiple_nodes(void)
{
    t_list *head = create_node("first");
    head->next = create_node("second");
    head->next->next = create_node("third");

    t_list *node4 = create_node("fourth");

    ft_lstadd_back(&head, node4);

    TEST_ASSERT_NOT_NULL(head->next->next->next);
    TEST_ASSERT_EQUAL_PTR(node4, head->next->next->next);
    TEST_ASSERT_EQUAL_STRING("fourth", head->next->next->next->content);
    TEST_ASSERT_NULL(head->next->next->next->next);

    free_list(head);
}

void test_ft_lstadd_back_null_node(void)
{
    t_list *head = create_node("first");

    ft_lstadd_back(&head, NULL);

    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_NULL(head->next);

    free_list(head);
}
