#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ft_printf.h"

void setup(void)
{
	cr_redirect_stdout();
}

Test(ft_printf, prints_character, .init = setup)
{
	ft_printf("Char: %c\n", 'A');
	cr_assert_stdout_eq_str("Char: A\n");
}
