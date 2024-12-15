#include "ft_printf.h"
#include "test_utils.h"

// Test printing a valid string
Test(ft_printf, normal_string, .init = setup) {
    ft_printf("String: %s\n", "Hello, World!");
    cr_assert_stdout_eq_str("String: Hello, World!\n");
}

// Test printing an empty string
Test(ft_printf, empty_string, .init = setup) {
	ft_printf("string: %s\n", "");
	cr_assert_stdout_eq_str("string: \n");
}

// Test printing a null string
Test(ft_printf, null_string, .init = setup) {
    ft_printf("String: %s\n", NULL);
    cr_assert_stdout_eq_str("String: (null)\n");
}

// Test printing a string with special characters
Test(ft_printf, special_characters, .init = setup) {
    ft_printf("String: %s\n", "Line1\nLine2\tTabbed");
    cr_assert_stdout_eq_str("String: Line1\nLine2\tTabbed\n");
}

// Test printing a string with a long length
Test(ft_printf, long_string, .init = setup) {
    char long_str[1024];
    memset(long_str, 'A', 1023);
    long_str[1023] = '\0';
    ft_printf("%s\n", long_str);

    char expected[1025];
    sprintf(expected, "%s\n", long_str);
    cr_assert_stdout_eq_str(expected);
}

// Test printing a string with mixed specifiers
Test(ft_printf, mixed_specifiers, .init = setup) {
    ft_printf("Name: %s, Age: %c\n", "Alice", '3');
    cr_assert_stdout_eq_str("Name: Alice, Age: 3\n");
}

// Test printing multiple strings
Test(ft_printf, multiple_strings, .init = setup) {
    ft_printf("%s, %s, %s!\n", "Hello", "World", "Alice");
    cr_assert_stdout_eq_str("Hello, World, Alice!\n");
}

// Test printing a string with leading and trailing whitespace
Test(ft_printf, leading_trailing_whitespace, .init = setup) {
    ft_printf("String: '%s'\n", "   spaced   ");
    cr_assert_stdout_eq_str("String: '   spaced   '\n");
}

// Test printing a string with embedded NULL
Test(ft_printf, embedded_null, .init = setup) {
    char str[] = "Hello\0World";
    ft_printf("String: %s\n", str);
    cr_assert_stdout_eq_str("String: Hello\n");  // Output stops at NULL
}
