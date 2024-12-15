#include "ft_printf.h"
#include "test_utils.h"

// Test printing positive decimal
Test(ft_printf, positive_decimal, .init = setup)
{
    ft_printf("Value: %d\n", 12345);
    cr_assert_stdout_eq_str("Value: 12345\n");
}

// Test printing negative decimal
Test(ft_printf, negative_decimal, .init = setup)
{
    ft_printf("Value: %d\n", -12345);
    cr_assert_stdout_eq_str("Value: -12345\n");
}

// Test printing zero
Test(ft_printf, zero, .init = setup)
{
    ft_printf("Value: %d\n", 0);
    cr_assert_stdout_eq_str("Value: 0\n");
}

// Test printing maximum decimal
Test(ft_printf, max_decimal, .init = setup)
{
    ft_printf("Value: %d\n", 2147483647);
    cr_assert_stdout_eq_str("Value: 2147483647\n");
}

// Test printing minimum decimal
Test(ft_printf, min_decimal, .init = setup)
{
    ft_printf("Value: %d\n", -2147483648);
    cr_assert_stdout_eq_str("Value: -2147483648\n");
}

// Test printing multiple decimals
Test(ft_printf, multiple_decimals, .init = setup)
{
    ft_printf("Values: %d, %d, %d\n", 1, -2, 3);
    cr_assert_stdout_eq_str("Values: 1, -2, 3\n");
}

// Test printing mixed specifiers with decimals
Test(ft_printf, mixed_specifiers_with_decimals, .init = setup)
{
    ft_printf("Char: %c, String: %s, Value: %d\n", 'A', "Test", 123);
    cr_assert_stdout_eq_str("Char: A, String: Test, Value: 123\n");
}
