#include "libft.h"
#include "unity.h"
#include <unistd.h>

void setUp(void) {}
void tearDown(void) {}

void test_ft_putendl_fd_basic(void)
{
    int pipe_ends[2];
    TEST_ASSERT_EQUAL_INT(0, pipe(pipe_ends));
    const int read_end  = pipe_ends[0];
    const int write_end = pipe_ends[1];

    ft_putendl_fd("Honda HRX 537", write_end);

    close(write_end);

    char buffer[16] = {0};
    const char *expected = "Honda HRX 537\n";

    TEST_ASSERT_EQUAL_INT(14, read(read_end, buffer, sizeof buffer));
    TEST_ASSERT_EQUAL_STRING(expected, buffer);

    close(read_end);
}

void test_ft_putendl_fd_empty(void)
{
    int pipe_ends[2];
    TEST_ASSERT_EQUAL_INT(0, pipe(pipe_ends));
    const int read_end  = pipe_ends[0];
    const int write_end = pipe_ends[1];

    ft_putendl_fd("", write_end);

    close(write_end);

    char buffer[16] = {0};
    const char *expected = "\n";

    TEST_ASSERT_EQUAL_INT(1, read(read_end, buffer, sizeof buffer));
    TEST_ASSERT_EQUAL_STRING(expected, buffer);

    close(read_end);
}
