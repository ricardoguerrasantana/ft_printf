#include "ft_printf.h"
#include "test_utils.h"

// Test printing hexadecimal values in uppercase format
Test(ft_printf, positive_hexadecimal_uppercase, .init = setup)
{
    char expected[100];
    int expected_len = sprintf(expected, "Value: %X\n", 12345);
    int len = ft_printf("Value: %X\n", 12345);
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(len, expected_len);
}

// Test printing zero in hexadecimal format
Test(ft_printf, zero_hexadecimal_uppercase, .init = setup)
{
    char expected[100];
    int expected_len = sprintf(expected, "Value: %X\n", 0);
    int len = ft_printf("Value: %X\n", 0);
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(len, expected_len);
}

// Test printing the maximum value for a 32-bit unsigned integer in hexadecimal format
Test(ft_printf, max_hexadecimal_uppercase, .init = setup)
{
    char expected[100];
    int expected_len = sprintf(expected, "Value: %lX\n", 4294967295);
    int len = ft_printf("Value: %X\n", 4294967295); // Max value for a 32-bit unsigned integer
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(len, expected_len);
}

// Test printing a large hexadecimal value in uppercase format
Test(ft_printf, large_hexadecimal_uppercase, .init = setup)
{
    char expected[100];
    int expected_len = sprintf(expected, "Value: %X\n", 123456789);
    int len = ft_printf("Value: %X\n", 123456789);
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(len, expected_len);
}

// Test printing multiple hexadecimal values in uppercase format
Test(ft_printf, multiple_hexadecimal_integers_uppercase, .init = setup)
{
    char expected[100];
    int expected_len = sprintf(expected, "Values: %X, %X, %X\n", 1, 0, 255);
    int len = ft_printf("Values: %X, %X, %X\n", 1, 0, 255);
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(len, expected_len);
}

// Test printing mixed specifiers with hexadecimal values in uppercase format
Test(ft_printf, mixed_specifiers_hexadecimal_uppercase, .init = setup)
{
    char expected[100];
    int expected_len = sprintf(expected, "Char: %c, String: %s, Value: %X\n", 'A', "Test", 255);
    int len = ft_printf("Char: %c, String: %s, Value: %X\n", 'A', "Test", 255);
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(len, expected_len);
}
