#include "ft_printf.h"
#include "test_utils.h"

// Test printing positive unsigned integer
Test(ft_printf, positive_unsigned_integer, .init = setup)
{
    ft_printf("Value: %u\n", 12345);
    cr_assert_stdout_eq_str("Value: 12345\n");
}

// Test printing zero unsigned integer
Test(ft_printf, zero_unsigned, .init = setup)
{
    ft_printf("Value: %u\n", 0);
    cr_assert_stdout_eq_str("Value: 0\n");
}

// Test printing max unsigned integer
Test(ft_printf, max_unsigned_integer, .init = setup)
{
    ft_printf("Value: %u\n", 4294967295); // Max value for a 32-bit unsigned integer
    cr_assert_stdout_eq_str("Value: 4294967295\n");
}

// Test printing large unsigned integer
Test(ft_printf, large_unsigned_integer, .init = setup)
{
    ft_printf("Value: %u\n", 123456789);
    cr_assert_stdout_eq_str("Value: 123456789\n");
}

// Test printing multiple unsigned integers
Test(ft_printf, multiple_unsigned_integers, .init = setup)
{
    ft_printf("Values: %u, %u, %u\n", 1, 0, 999);
    cr_assert_stdout_eq_str("Values: 1, 0, 999\n");
}

// Test printing mixed specifiers with unsigned integers
Test(ft_printf, mixed_specifiers_unsigned, .init = setup)
{
    ft_printf("Char: %c, String: %s, Value: %u\n", 'A', "Test", 12345);
    cr_assert_stdout_eq_str("Char: A, String: Test, Value: 12345\n");
}
