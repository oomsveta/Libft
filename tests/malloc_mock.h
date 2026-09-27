#pragma once

#include <stdlib.h>
#include <stdbool.h>

void *malloc_mock(size_t size);
void malloc_mock_failure(bool should_fail);
void malloc_mock_fail_after(size_t nbr_of_calls);
void malloc_mock_reset(void);
