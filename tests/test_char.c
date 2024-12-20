#include "ft_printf.h"
#include "test_utils.h"

// Test printing a valid character
Test(ft_printf, prints_character, .init = setup)
{
    ft_printf("Char: %c\n", 'A');
    cr_assert_stdout_eq_str("Char: A\n");
}

// Test printing multiple characters
Test(ft_printf, prints_multiple_characters, .init = setup)
{
    ft_printf("Chars: %c, %c, %c\n", 'A', 'B', 'C');
    cr_assert_stdout_eq_str("Chars: A, B, C\n");
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


Test(ft_printf, francinette_test_5, .init = setup)
{
	ft_printf(" %c %c %c ", '0', 0, '1');
	cr_assert_stdout_eq_str(" 0  1 ");
}

Test(ft_printf, francinette_test_8, .init = setup)
{
	ft_printf(" %c %c %c ", '2', '1', 0);
	cr_assert_stdout_eq_str(" 2 1  ");
}

Test(ft_printf, francinette_test_9, .init = setup)
{
	ft_printf(" %c %c %c ", 0, '1', '2');
	cr_assert_stdout_eq_str("  1 2 ");
}

Test(ft_printf, francinette_test_category_mix, .init = setup)
{
	ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	cr_assert_stdout_eq_str("%A%42%42%42%42%2a%2A%% %B%-42%-42%-42%4294967254%ffffffd6%2A%% %C%0%0%0%0%0%2A%% %");
}
