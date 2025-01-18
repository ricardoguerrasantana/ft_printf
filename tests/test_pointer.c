#include "ft_printf.h"
#include "test_utils.h"

// Test printing a valid pointer
Test(ft_printf, valid_pointer, .init = setup)
{
    int x = 42;
    ft_printf("Address: %p\n", &x);
    char expected[100];
    sprintf(expected, "Address: %p\n", (void *)&x);
    cr_assert_stdout_eq_str(expected); // Compare output to standard printf
}

// Test printing a null pointer
Test(ft_printf, null_pointer, .init = setup)
{
	ft_printf("Address: %p\n", NULL);
	char expected[100];
	sprintf(expected, "Address: %p\n", NULL);
	cr_assert_stdout_eq_str(expected); // Compare output to standard printf
}

// Test printing multiple pointers
Test(ft_printf, multiple_pointers, .init = setup)
{
    int a = 10, b = 20;
    ft_printf("Ptr1: %p, Ptr2: %p\n", &a, &b);
    char expected[200];
    sprintf(expected, "Ptr1: %p, Ptr2: %p\n", (void *)&a, (void *)&b);
    cr_assert_stdout_eq_str(expected);
}

// Test printing a pointer to a string
Test(ft_printf, dynamic_memory_pointer, .init = setup)
{
    char *ptr = malloc(10);
    ft_printf("Heap Ptr: %p\n", ptr);
    char expected[100];
    sprintf(expected, "Heap Ptr: %p\n", (void *)ptr);
    cr_assert_stdout_eq_str(expected);
    free(ptr); // Free allocated memory
}

	// Test printing the maximum address
Test(ft_printf, max_address, .init = setup)
{
    void *ptr = (void *)0xFFFFFFFFFFFFFFFF; // Simulate max pointer
    ft_printf("Max Address: %p\n", ptr);
	char expected[100];
	sprintf(expected, "Max Address: %p\n", ptr);
    cr_assert_stdout_eq_str(expected);
}

// Test printing a zero pointer
Test(ft_printf, zero_pointer, .init = setup)
{
    void *ptr = (void *)0;
    ft_printf("Literal Zero: %p\n", ptr);
	char expected[100];
	sprintf(expected, "Literal Zero: %p\n", ptr);
    cr_assert_stdout_eq_str(expected);
}
