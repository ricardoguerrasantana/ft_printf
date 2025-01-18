#include "ft_printf.h"
#include "test_utils.h"

// Test printing positive decimal
Test(ft_printf, positive_decimal, .init = setup)
{
    int len = ft_printf("Value: %d\n", 12345);
	char expected[100];
	int expected_len = sprintf(expected, "Value: %d\n", 12345);
	cr_assert_stdout_eq_str(expected);
	cr_assert_eq(len, expected_len);
}

// Test printing negative decimal
Test(ft_printf, negative_decimal, .init = setup)
{
    int len = ft_printf("Value: %d\n", -12345);
    char expected[100];
	int expected_len = sprintf(expected, "Value: %d\n", -12345);
	cr_assert_stdout_eq_str(expected);
	cr_assert_eq(len, expected_len);
}

// Test printing zero
Test(ft_printf, zero, .init = setup)
{
    int len = ft_printf("Value: %d\n", 0);
	char expected[100];
	int expected_len = sprintf(expected, "Value: %d\n", 0);
	cr_assert_stdout_eq_str(expected);
	cr_assert_eq(len, expected_len);
}

// Test printing maximum decimal
Test(ft_printf, max_decimal, .init = setup)
{
    int len = ft_printf("Value: %d\n", 2147483647);
    char expected[100];
	int expected_len = sprintf(expected, "Value: %d\n", 2147483647);
	cr_assert_stdout_eq_str(expected);
	cr_assert_eq(len, expected_len);
}

// Test printing minimum decimal
Test(ft_printf, min_decimal, .init = setup)
{
    int len = ft_printf("Value: %d\n", -2147483647);
    char expected[100];
	int expected_len = sprintf(expected, "Value: %d\n", -2147483647);
	cr_assert_stdout_eq_str(expected);
	cr_assert_eq(len, expected_len);
}

// Test printing multiple decimals
Test(ft_printf, multiple_decimals, .init = setup)
{
    int len = ft_printf("Values: %d, %d, %d\n", 1, -2, 3);
    char expected[100];
	int expected_len = sprintf(expected, "Values: %d, %d, %d\n", 1, -2, 3);
	cr_assert_stdout_eq_str(expected);
	cr_assert_eq(len, expected_len);
}

// Test printing mixed specifiers with decimals
Test(ft_printf, mixed_specifiers_with_decimals, .init = setup)
{
    int len = ft_printf("Char: %c, String: %s, Value: %d\n", 'A', "Test", 123);
    char expected[100];
	int expected_len = sprintf(expected, "Char: %c, String: %s, Value: %d\n", 'A', "Test", 123);
	cr_assert_stdout_eq_str(expected);
	cr_assert_eq(len, expected_len);
}
