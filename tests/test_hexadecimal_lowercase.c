#include "ft_printf.h"
#include "test_utils.h"

// Test printing positive hexadecimal
Test(ft_printf, positive_hexadecimal, .init = setup)
{
    int len = ft_printf("Value: %x\n", 12345);
	char expected[100];
	int expected_len = sprintf(expected, "Value: %x\n", 12345);
	cr_assert_stdout_eq_str(expected);
	cr_assert_eq(len, expected_len);
}

// Test printing zero hexadecimal
Test(ft_printf, zero_hexadecimal, .init = setup)
{
    int len = ft_printf("Value: %x\n", 0);
    char expected[100];
	int expected_len = sprintf(expected, "Value: %x\n", 0);
	cr_assert_stdout_eq_str(expected);
	cr_assert_eq(len, expected_len);
}

// Test printing max hexadecimal
Test(ft_printf, max_hexadecimal, .init = setup)
{
    int len = ft_printf("Value: %x\n", 4294967295); // Max value for a 32-bit unsigned integer
    char expected[100];
	int expected_len = sprintf(expected, "Value: %lx\n", 4294967295);
	cr_assert_stdout_eq_str(expected);
	cr_assert_eq(len, expected_len);
}

// Test printing large hexadecimal
Test(ft_printf, large_hexadecimal, .init = setup)
{
    int len = ft_printf("Value: %x\n", 123456789);
	char expected[100];
	int expected_len = sprintf(expected, "Value: %x\n", 123456789);
	cr_assert_stdout_eq_str(expected);
	cr_assert_eq(len, expected_len);
}

// Test printing multiple hexadecimal
Test(ft_printf, multiple_hexadecimal, .init = setup)
{
    int len = ft_printf("Values: %x, %x, %x\n", 1, 0, 255);
	char expected[100];
	int expected_len = sprintf(expected, "Values: %x, %x, %x\n", 1, 0, 255);
	cr_assert_stdout_eq_str(expected);
	cr_assert_eq(len, expected_len);
}

// Test printing mixed specifiers with hexadecimal
Test(ft_printf, mixed_specifiers_hexadecimal, .init = setup)
{
    int len = ft_printf("Char: %c, String: %s, Value: %x\n", 'A', "Test", 255);
    char expected[100];
	int expected_len = sprintf(expected, "Char: %c, String: %s, Value: %x\n", 'A', "Test", 255);
	cr_assert_stdout_eq_str(expected);
	cr_assert_eq(len, expected_len);
}
