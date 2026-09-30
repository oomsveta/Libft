#include "libft.h"
#include "unity.h"
#include <stdlib.h>

static size_t g_call_count = 0;

void setUp(void)
{
    g_call_count = 0;
}

void tearDown(void) {}

static void dummy_fn(void *content)
{
    char *str = (char *)content;
    if (str && str[0] != '\0') {
        // change the first letter to 'X' so that we can tell which nodes have been visited
        str[0] = 'X';
    }
    g_call_count += 1;
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

static void free_list(t_list *lst)
{
    t_list *tmp;
    while (lst) {
        tmp = lst->next;
        free(lst);
        lst = tmp;
    }
}

void test_ft_lstiter_multiple_nodes(void)
{
    t_list *head = create_node((char []){"first"});
    head->next = create_node((char []){"second"});
    head->next->next = create_node((char []){"third"});

    ft_lstiter(head, dummy_fn);

    TEST_ASSERT_EQUAL_size_t(3, g_call_count);
    
    // verify that the content has been modified by dummy_fn
    TEST_ASSERT_EQUAL_STRING("Xirst", head->content);
    TEST_ASSERT_EQUAL_STRING("Xecond", head->next->content);
    TEST_ASSERT_EQUAL_STRING("Xhird", head->next->next->content);

    free_list(head);
}

void test_ft_lstiter_single_node(void)
{
    t_list *head = create_node((char []){"only"});

    ft_lstiter(head, dummy_fn);

    TEST_ASSERT_EQUAL_size_t(1, g_call_count);
    TEST_ASSERT_EQUAL_STRING("Xnly", head->content);

    free_list(head);
}

void test_ft_lstiter_empty_list(void)
{
    ft_lstiter(NULL, dummy_fn);

    TEST_ASSERT_EQUAL_size_t(0, g_call_count);
}
