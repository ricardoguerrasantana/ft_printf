#include "ft_printf.h"
#include "test_utils.h"

// Test printing a single percent sign
Test(ft_printf, prints_single_percent, .init = setup)
{
    char expected[100];
    int expected_len = sprintf(expected, "Percent: %%\n");
    int len = ft_printf("Percent: %%\n");
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(len, expected_len);
}

// Test printing percent signs without any additional text
Test(ft_printf, prints_percent_alone, .init = setup)
{
    char expected[100];
    int expected_len = sprintf(expected, "%%");
    int len = ft_printf("%%");
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(len, expected_len);
}

// Test printing multiple percent signs
Test(ft_printf, prints_multiple_percent, .init = setup)
{
    char expected[100];
    int expected_len = sprintf(expected, "%%%%\n");
    int len = ft_printf("%%%%\n");
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(len, expected_len);
}

// Test percent signs with other text
Test(ft_printf, prints_percent_with_text, .init = setup)
{
    char expected[100];
    int expected_len = sprintf(expected, "Loading%% Complete\n");
    int len = ft_printf("Loading%% Complete\n");
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(len, expected_len);
}

// Test percent signs with no additional formatting
Test(ft_printf, prints_percent_no_formatting, .init = setup)
{
    char expected[100];
    int expected_len = sprintf(expected, "%% %%\n");
    int len = ft_printf("%% %%\n");
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(len, expected_len);
}
