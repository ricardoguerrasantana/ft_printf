#include "ft_printf.h"
#include "test_utils.h"

// Test printing hexadecimal values in uppercase format
Test(ft_printf, positive_hexadecimal_uppercase, .init = setup)
{
    ft_printf("Value: %X\n", 12345);
    cr_assert_stdout_eq_str("Value: 3039\n"); // 12345 in hexadecimal, uppercase
}

// Test printing zero in hexadecimal format
Test(ft_printf, zero_hexadecimal_uppercase, .init = setup)
{
    ft_printf("Value: %X\n", 0);
    cr_assert_stdout_eq_str("Value: 0\n");
}

// Test printing the maximum value for a 32-bit unsigned integer in hexadecimal format
Test(ft_printf, max_hexadecimal_uppercase, .init = setup)
{
    ft_printf("Value: %X\n", 4294967295); // Max value for a 32-bit unsigned integer
    cr_assert_stdout_eq_str("Value: FFFFFFFF\n");
}

// Test printing a large hexadecimal value in uppercase format
Test(ft_printf, large_hexadecimal_uppercase, .init = setup)
{
    ft_printf("Value: %X\n", 123456789);
    cr_assert_stdout_eq_str("Value: 75BCD15\n"); // 123456789 in hexadecimal, uppercase
}

// Test priting multiple hexadecimal values in uppercase format
Test(ft_printf, multiple_hexadecimal_integers_uppercase, .init = setup)
{
    ft_printf("Values: %X, %X, %X\n", 1, 0, 255);
    cr_assert_stdout_eq_str("Values: 1, 0, FF\n"); // Multiple hex values, uppercase
}

// Test printing mixed specifiers with hexadecimal values in uppercase format
Test(ft_printf, mixed_specifiers_hexadecimal_uppercase, .init = setup)
{
    ft_printf("Char: %c, String: %s, Value: %X\n", 'A', "Test", 255);
    cr_assert_stdout_eq_str("Char: A, String: Test, Value: FF\n");
}
