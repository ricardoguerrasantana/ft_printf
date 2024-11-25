#include "ft_printf.h"
#include "test_utils.h"

// Test printing a valid character
Test(ft_printf, prints_character, .init = setup)
{
    ft_printf("Char: %c\n", 'A');
    cr_assert_stdout_eq_str("Char: A\n");
}

// Test printing a null character
Test(ft_printf, prints_null_character, .init = setup)
{
    ft_printf("Char: %c\n", '\0');
    cr_assert_stdout_eq_str("Char: \n");
}

// Test printing a whitespace character
Test(ft_printf, prints_whitespace, .init = setup)
{
    ft_printf("Char: %c\n", ' ');
    cr_assert_stdout_eq_str("Char:  \n"); // Note: Two spaces, one from ' ' and one from '\n'
}

// Test printing a special character
Test(ft_printf, prints_special_character, .init = setup)
{
    ft_printf("Char: %c\n", '@');
    cr_assert_stdout_eq_str("Char: @\n");
}

// Test printing a numeric character
Test(ft_printf, prints_numeric_character, .init = setup)
{
    ft_printf("Char: %c\n", '1');
    cr_assert_stdout_eq_str("Char: 1\n");
}

// Test printing the last valid ASCII character (DEL)
Test(ft_printf, prints_last_ascii_character, .init = setup)
{
    ft_printf("Char: %c\n", 127);
    cr_assert_stdout_eq_str("Char: \x7F\n");
}

// Test printing an extended ASCII character (if applicable in your environment)
Test(ft_printf, prints_extended_ascii_character, .init = setup)
{
    ft_printf("Char: %c\n", 255); // Extended ASCII value
    cr_assert_stdout_eq_str("Char: \xFF\n");
}
