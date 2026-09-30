#include "libft.h"
#include "unity.h"
#include <stdlib.h>
#include <string.h>

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

void test_ft_lstdelone_single_node(void)
{
    t_list *node = create_node("delete_me");

    ft_lstdelone(node, dummy_del);

    TEST_ASSERT_EQUAL_size_t(1, g_delete_fn_call_count);
}
