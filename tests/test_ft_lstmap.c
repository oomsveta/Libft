#include "libft.h"
#include "malloc_mock.h"
#include "unity.h"
#include <string.h>

static size_t g_delete_fn_call_count = 0;

void setUp(void)
{
    malloc_mock_reset();
    g_delete_fn_call_count = 0;
}

void tearDown(void)
{
    malloc_mock_reset();
}

static void *dummy_fn(void *content)
{
    char *str = strdup((char *)content);
    if (str && str[0] != '\0') {
        str[0] = 'X'; 
    }
    return (str);
}

static void dummy_delete(void *content)
{
    free(content);
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

static void free_list(t_list *lst)
{
    t_list *tmp;
    while (lst) {
        tmp = lst->next;
        free(lst->content);
        free(lst);
        lst = tmp;
    }
}

void test_ft_lstmap_success(void)
{
    t_list *head = create_node(strdup("first"));
    head->next = create_node(strdup("second"));
    head->next->next = create_node(strdup("third"));

    t_list *new_list = ft_lstmap(head, dummy_fn, dummy_delete);

    TEST_ASSERT_NOT_NULL(new_list);
    
    // verify that the new list has been transformed correctly
    TEST_ASSERT_EQUAL_STRING("Xirst", new_list->content);
    TEST_ASSERT_EQUAL_STRING("Xecond", new_list->next->content);
    TEST_ASSERT_EQUAL_STRING("Xhird", new_list->next->next->content);

    // verify that the original list has been left untouched
    TEST_ASSERT_EQUAL_STRING("first", head->content);

    free_list(head);
    free_list(new_list);
}

void test_ft_lstmap_empty_list(void)
{
    t_list *new_list = ft_lstmap(NULL, dummy_fn, dummy_delete);
    
    TEST_ASSERT_NULL(new_list);
    TEST_ASSERT_EQUAL_size_t(0, g_delete_fn_call_count);
}

void test_ft_lstmap_malloc_fail_first_node(void)
{
    t_list *head = create_node(strdup("first"));
    
    // fail the very first node allocation
    malloc_mock_failure(true); 
    
    t_list *new_list = ft_lstmap(head, dummy_fn, dummy_delete);
    
    TEST_ASSERT_NULL(new_list);
    
    // the content made by dummy_fn must be cleaned up by dummy_delete
    TEST_ASSERT_EQUAL_size_t(1, g_delete_fn_call_count); 
    
    free_list(head);
}

void test_ft_lstmap_malloc_fail_second_node(void)
{
    t_list *head = create_node(strdup("first"));
    head->next = create_node(strdup("second"));

    // fail the second node allocation
    malloc_mock_fail_after(2); 
    
    t_list *new_list = ft_lstmap(head, dummy_fn, dummy_delete);
    
    TEST_ASSERT_NULL(new_list);
    
    // delete must be called TWICE: 
    // 1. to destroy the second mapped content whose node failed to allocate
    // 2. to destroy the first node that was successfully allocated earlier
    TEST_ASSERT_EQUAL_size_t(2, g_delete_fn_call_count); 
    
    // the original list must still be fully intact
    TEST_ASSERT_EQUAL_STRING("first", head->content);
    TEST_ASSERT_EQUAL_STRING("second", head->next->content);

    free_list(head);
}
