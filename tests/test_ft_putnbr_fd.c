#include "libft.h"
#include "unity.h"
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void setUp(void) {}
void tearDown(void) {}

void test_ft_putnbr_fd_basic(void)
{
    int pipe_ends[2];
    TEST_ASSERT_EQUAL_INT(0, pipe(pipe_ends));
    const int read_end = pipe_ends[0];
    const int write_end = pipe_ends[1];

    ft_putnbr_fd(42, write_end);

    close(write_end);

    char buffer[8] = {0};

    TEST_ASSERT_EQUAL_INT(2, read(read_end, buffer, sizeof buffer));
    TEST_ASSERT_EQUAL_STRING("42", buffer);

    close(read_end);
}

void test_ft_putnbr_fd_extrema(void)
{
    int pipe_ends[2];
    TEST_ASSERT_EQUAL_INT(0, pipe(pipe_ends));
    const int read_end = pipe_ends[0];
    const int write_end = pipe_ends[1];

    ft_putnbr_fd(INT_MAX, write_end);

    char buffer[64] = {0};
    char expected[64];
    sprintf(expected, "%d", INT_MAX);

    TEST_ASSERT_EQUAL_INT(strlen(expected), read(read_end, buffer, sizeof buffer));
    TEST_ASSERT_EQUAL_STRING(expected, buffer);

    ft_putnbr_fd(INT_MIN, write_end);
    
    close(write_end);

    memset(buffer, 0, sizeof buffer);
    sprintf(expected, "%d", INT_MIN);

    TEST_ASSERT_EQUAL_INT(strlen(expected), read(read_end, buffer, sizeof buffer));
    TEST_ASSERT_EQUAL_STRING(expected, buffer);

    close(read_end);
}

void test_ft_putnbr_fd_zero(void)
{
    int pipe_ends[2];
    TEST_ASSERT_EQUAL_INT(0, pipe(pipe_ends));
    const int read_end = pipe_ends[0];
    const int write_end = pipe_ends[1];

    ft_putnbr_fd(0, write_end);

    close(write_end);

    char buffer[8] = {0};

    TEST_ASSERT_EQUAL_INT(1, read(read_end, buffer, sizeof buffer));
    TEST_ASSERT_EQUAL_STRING("0", buffer);

    close(read_end);
}
