#include "ft_printf.h"
#include "test_utils.h"

// Test printing positive integer
Test(ft_printf, positive_integer, .init = setup)
{
    char expected[100];
    int expected_len = sprintf(expected, "Value: %i\n", 12345);
    int len = ft_printf("Value: %i\n", 12345);
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(len, expected_len);
}

// Test printing negative integer
Test(ft_printf, negative_integer, .init = setup)
{
    char expected[100];
    int expected_len = sprintf(expected, "Value: %i\n", -12345);
    int len = ft_printf("Value: %i\n", -12345);
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(len, expected_len);
}

// Test printing zero integer
Test(ft_printf, zero_integer, .init = setup)
{
    char expected[100];
    int expected_len = sprintf(expected, "Value: %i\n", 0);
    int len = ft_printf("Value: %i\n", 0);
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(len, expected_len);
}

// Test printing maximum integer
Test(ft_printf, max_integer, .init = setup)
{
    char expected[100];
    int expected_len = sprintf(expected, "Value: %i\n", 2147483647);
    int len = ft_printf("Value: %i\n", 2147483647);
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(len, expected_len);
}

// Test printing minimum integer
Test(ft_printf, min_integer, .init = setup)
{
    char expected[100];
    int expected_len = sprintf(expected, "Value: %i\n", -2147483647);
    int len = ft_printf("Value: %i\n", -2147483647);
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(len, expected_len);
}

// Test printing multiple integers
Test(ft_printf, multiple_integers, .init = setup)
{
    char expected[100];
    int expected_len = sprintf(expected, "Values: %i, %i, %i\n", 1, -2, 3);
    int len = ft_printf("Values: %i, %i, %i\n", 1, -2, 3);
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(len, expected_len);
}

// Test printing mixed specifiers with integers
Test(ft_printf, mixed_specifiers_with_integers, .init = setup)
{
    char expected[100];
    int expected_len = sprintf(expected, "Char: %c, String: %s, Value: %i\n", 'A', "Test", 123);
    int len = ft_printf("Char: %c, String: %s, Value: %i\n", 'A', "Test", 123);
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(len, expected_len);
}
