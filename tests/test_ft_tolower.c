#include "libft.h"
#include "unity.h"
#include <ctype.h>
#include <limits.h>
#include <stdio.h>

#if defined(__APPLE__)
#include <xlocale.h>
#else
#include <locale.h>
#endif

void setUp(void) {}
void tearDown(void) {}

void test_ft_tolower(void)
{
    locale_t c_locale = newlocale(LC_CTYPE_MASK, "C", NULL);

    for (int c = '\0'; c <= UCHAR_MAX; ++c) {
        TEST_ASSERT_EQUAL_INT(tolower_l(c, c_locale), ft_tolower(c));
    }
    TEST_ASSERT_EQUAL_INT(tolower_l(EOF, c_locale), ft_tolower(EOF));

    freelocale(c_locale);
}
