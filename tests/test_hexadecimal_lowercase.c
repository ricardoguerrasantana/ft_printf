#include "ft_printf.h"
#include "test_utils.h"

// Test printing positive hexadecimal
Test(ft_printf, positive_hexadecimal, .init = setup)
{
    ft_printf("Value: %x\n", 12345);
    cr_assert_stdout_eq_str("Value: 3039\n"); // 12345 in hexadecimal
}

// Test printing zero hexadecimal
Test(ft_printf, zero_hexadecimal, .init = setup)
{
    ft_printf("Value: %x\n", 0);
    cr_assert_stdout_eq_str("Value: 0\n");
}

// Test printing max hexadecimal
Test(ft_printf, max_hexadecimal, .init = setup)
{
    ft_printf("Value: %x\n", 4294967295); // Max value for a 32-bit unsigned integer
    cr_assert_stdout_eq_str("Value: ffffffff\n");
}

// Test printing large hexadecimal
Test(ft_printf, large_hexadecimal, .init = setup)
{
    ft_printf("Value: %x\n", 123456789);
    cr_assert_stdout_eq_str("Value: 75bcd15\n"); // 123456789 in hexadecimal
}

// Test printing multiple hexadecimal
Test(ft_printf, multiple_hexadecimal, .init = setup)
{
    ft_printf("Values: %x, %x, %x\n", 1, 0, 255);
    cr_assert_stdout_eq_str("Values: 1, 0, ff\n"); // Multiple hex values
}

// Test printing mixed specifiers with hexadecimal
Test(ft_printf, mixed_specifiers_hexadecimal, .init = setup)
{
    ft_printf("Char: %c, String: %s, Value: %x\n", 'A', "Test", 255);
    cr_assert_stdout_eq_str("Char: A, String: Test, Value: ff\n");
}
