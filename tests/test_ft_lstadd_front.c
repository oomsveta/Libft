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

void test_ft_lstadd_front_empty_list(void)
{
    t_list *head = NULL;
    t_list *node = create_node("first");

    ft_lstadd_front(&head, node);

    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_PTR(node, head);
    TEST_ASSERT_EQUAL_STRING("first", head->content);
    TEST_ASSERT_NULL(head->next);

    free_list(head);
}

void test_ft_lstadd_front_single_node(void)
{
    t_list *head = create_node("old_front");
    t_list *new_node = create_node("new_front");

    ft_lstadd_front(&head, new_node);

    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_PTR(new_node, head);
    TEST_ASSERT_EQUAL_STRING("new_front", head->content);
    
    TEST_ASSERT_NOT_NULL(head->next);
    TEST_ASSERT_EQUAL_STRING("old_front", head->next->content);
    TEST_ASSERT_NULL(head->next->next);

    free_list(head);
}

void test_ft_lstadd_front_multiple_nodes(void)
{
    t_list *head = create_node("second");
    head->next = create_node("third");
    
    t_list *new_node = create_node("first");

    ft_lstadd_front(&head, new_node);

    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_PTR(new_node, head);
    TEST_ASSERT_EQUAL_STRING("first", head->content);
    
    TEST_ASSERT_NOT_NULL(head->next);
    TEST_ASSERT_EQUAL_STRING("second", head->next->content);
    
    TEST_ASSERT_NOT_NULL(head->next->next);
    TEST_ASSERT_EQUAL_STRING("third", head->next->next->content);
    TEST_ASSERT_NULL(head->next->next->next);

    free_list(head);
}
