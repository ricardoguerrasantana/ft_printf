#include "ft_printf.h"
#include "test_utils.h"

// Test printing a single percent sign
Test(ft_printf, prints_single_percent, .init = setup)
{
    ft_printf("Percent: %%\n");
    cr_assert_stdout_eq_str("Percent: %\n");
}

// Test printing percent signs without any additional text
Test(ft_printf, prints_percent_alone, .init = setup)
{
    ft_printf("%%");
    cr_assert_stdout_eq_str("%");
}

// Test printing multiple percent signs
Test(ft_printf, prints_multiple_percent, .init = setup)
{
    ft_printf("%%%%\n");
    cr_assert_stdout_eq_str("%%\n");
}

// Test percent signs with other text
Test(ft_printf, prints_percent_with_text, .init = setup)
{
    ft_printf("Loading%% Complete\n");
    cr_assert_stdout_eq_str("Loading% Complete\n");
}

// Test percent signs with no additional formatting
Test(ft_printf, prints_percent_no_formatting, .init = setup)
{
    ft_printf("%% %%\n");
    cr_assert_stdout_eq_str("% %\n");
}
