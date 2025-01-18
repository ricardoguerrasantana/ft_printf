#include "ft_printf.h"
#include "test_utils.h"

// Test printing positive unsigned integer
Test(ft_printf, positive_unsigned_integer, .init = setup)
{
    char expected[100];
    int expected_len = sprintf(expected, "Value: %u\n", 12345);
    int len = ft_printf("Value: %u\n", 12345);
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(len, expected_len);
}

// Test printing zero unsigned integer
Test(ft_printf, zero_unsigned, .init = setup)
{
    char expected[100];
    int expected_len = sprintf(expected, "Value: %u\n", 0);
    int len = ft_printf("Value: %u\n", 0);
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(len, expected_len);
}

// Test printing max unsigned integer
Test(ft_printf, max_unsigned_integer, .init = setup)
{
    char expected[100];
    int expected_len = sprintf(expected, "Value: %lu\n", 4294967295); // Max value for a 32-bit unsigned integer
    int len = ft_printf("Value: %u\n", 4294967295);
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(len, expected_len);
}

// Test printing large unsigned integer
Test(ft_printf, large_unsigned_integer, .init = setup)
{
    char expected[100];
    int expected_len = sprintf(expected, "Value: %u\n", 123456789);
    int len = ft_printf("Value: %u\n", 123456789);
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(len, expected_len);
}

// Test printing multiple unsigned integers
Test(ft_printf, multiple_unsigned_integers, .init = setup)
{
    char expected[100];
    int expected_len = sprintf(expected, "Values: %u, %u, %u\n", 1, 0, 999);
    int len = ft_printf("Values: %u, %u, %u\n", 1, 0, 999);
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(len, expected_len);
}

// Test printing mixed specifiers with unsigned integers
Test(ft_printf, mixed_specifiers_unsigned, .init = setup)
{
    char expected[100];
    int expected_len = sprintf(expected, "Char: %c, String: %s, Value: %u\n", 'A', "Test", 12345);
    int len = ft_printf("Char: %c, String: %s, Value: %u\n", 'A', "Test", 12345);
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(len, expected_len);
}
