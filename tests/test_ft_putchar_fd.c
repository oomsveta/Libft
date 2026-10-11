#include "libft.h"
#include "unity.h"
#include <unistd.h>

void setUp(void) {}
void tearDown(void) {}

void test_ft_putchar_fd_basic(void)
{
    int pipe_ends[2];
    TEST_ASSERT_EQUAL_INT(0, pipe(pipe_ends));
    const int read_end  = pipe_ends[0];
    const int write_end = pipe_ends[1];

    ft_putchar_fd('A', write_end);

    close(write_end);

    char buffer[8] = {0};

    TEST_ASSERT_EQUAL_INT(1, read(read_end, buffer, 2));
    TEST_ASSERT_EQUAL_CHAR('A', buffer[0]);

    close(read_end);
}
