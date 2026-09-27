#include <stdlib.h>
#include <stdbool.h>

#undef malloc

static size_t g_call_count = 0;
static bool g_should_fail = false;
static size_t g_should_fail_after = 0;

void *malloc_mock(size_t size)
{
    g_call_count += 1;
    if (g_should_fail) {
        return NULL;
    }
    if (g_should_fail_after != 0 && g_call_count >= g_should_fail_after) {
        return NULL;
    }
    return malloc(size);
}

void malloc_mock_failure(bool should_fail)
{
    g_should_fail = should_fail;
}

void malloc_mock_fail_after(size_t nbr_of_calls)
{
    g_should_fail_after = nbr_of_calls;
}

void malloc_mock_reset(void)
{
    g_call_count = 0;
    g_should_fail = false;
    g_should_fail_after = 0;
}
