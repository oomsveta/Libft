#include "libft.h"
#include "unity.h"
#include <ctype.h>
#include <limits.h>
#include <stdio.h>

// Unity's test runner generator script copies all include directives blindly,
// ignoring any surrounding conditionals. The trick below prevents the script
// from unconditionally including xlocale.h, which would fail on Linux systems.
#if defined(__APPLE__)
# define LOCALE_H_NAME <xlocale.h>
#else
# define LOCALE_H_NAME <locale.h>
#endif
#include LOCALE_H_NAME

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
