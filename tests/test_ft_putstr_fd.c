#include "libft.h"
#include "unity.h"
#include <string.h>
#include <unistd.h>

void setUp(void) {}
void tearDown(void) {}

void test_ft_putstr_fd_basic(void)
{
    int pipe_ends[2];
    TEST_ASSERT_EQUAL_INT(0, pipe(pipe_ends));
    const int read_end = pipe_ends[0];
    const int write_end = pipe_ends[1];
    const char str[] = "somebody once";

    ft_putstr_fd((char *)str, write_end);

    close(write_end);

    char buffer[16] = {0};
    TEST_ASSERT_EQUAL_INT(strlen(str), read(read_end, buffer, sizeof buffer));
    TEST_ASSERT_EQUAL_STRING(str, buffer);

    close(read_end);
}
