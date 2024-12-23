# ft_printf

## Overview
The `ft_printf` project is a reimplementation of the standard C `printf` function, capable of formatted output. This implementation supports a variety of format specifiers and adheres to the constraints provided by the subject. The goal of the project is to deepen the understanding of variadic functions and efficient string handling in C.

## Features
The `ft_printf` implementation supports the following format specifiers:

| Specifier | Description                                   |
|-----------|-----------------------------------------------|
| `%c`      | Prints a single character.                   |
| `%s`      | Prints a string (null-safe).                 |
| `%p`      | Prints a pointer in hexadecimal format.      |
| `%d`/`%i` | Prints a signed decimal integer.             |
| `%u`      | Prints an unsigned decimal integer.          |
| `%x`      | Prints an unsigned hexadecimal (lowercase).  |
| `%X`      | Prints an unsigned hexadecimal (uppercase).  |

## Directory Structure

```
.
├── src/               # Source files for `ft_printf`
│   ├── ft_printf.c
│   ├── ft_handle_conversions.c
│   ├── ft_print_char.c
│   ├── ft_print_string.c
│   ├── ft_print_pointer.c
│   ├── ft_print_number.c
│   ├── ft_print_unsigned.c
│   ├── ft_print_hexadecimal.c
│   ├── ft_print_hexadecimal_upper.c
├── include/           # Header files
│   └── ft_printf.h
├── obj/               # Compiled object files (generated automatically)
├── tests/             # Test cases for Criterion framework
│   ├── test_char.c
│   ├── test_string.c
│   ├── test_pointer.c
│   ├── test_number.c
│   ├── test_unsigned.c
│   ├── test_hexadecimal.c
│   ├── test_hexadecimal_upper.c
├── Makefile           # Compilation and testing automation
└── README.md          # Project documentation
```

## Compilation
The project can be compiled using the provided `Makefile`. The default target generates the `libftprintf.a` library.

```bash
make
```

To clean object files:
```bash
make clean
```

To clean object files and the library:
```bash
make fclean
```

To rebuild everything:
```bash
make re
```

## Testing

### Unit Testing with Criterion
The `tests/` directory contains unit tests for all implemented features. You can run the tests using the following command:

```bash
make test
```

### Testing with TAP Format
To generate test output in the TAP (Test Anything Protocol) format:
```bash
make test-tap
```

### Memory Leak Detection with Valgrind
To run the tests with Valgrind for memory leak detection:
```bash
make valgrind
```

## Examples
Here are some usage examples of the `ft_printf` function:

### Basic Examples
```c
ft_printf("Character: %c\n", 'A');
// Output: Character: A

ft_printf("String: %s\n", "Hello, World!");
// Output: String: Hello, World!

ft_printf("Pointer: %p\n", &main);
// Output: Pointer: 0x12345678 (example address)

ft_printf("Decimal: %d\n", 42);
// Output: Decimal: 42

ft_printf("Unsigned: %u\n", 300);
// Output: Unsigned: 300

ft_printf("Hexadecimal (lowercase): %x\n", 255);
// Output: Hexadecimal (lowercase): ff

ft_printf("Hexadecimal (uppercase): %X\n", 255);
// Output: Hexadecimal (uppercase): FF
```

## Norminette
Ensure the project adheres to 42's coding standard by running:

```bash
make norm
```

## License
This project is developed as part of the 42 curriculum and is subject to the rules and constraints of the program.

## Author
Ricardo Guerra Santana
