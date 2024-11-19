# ft_printf

This repository contains my implementation of the `printf` function in C as part of the 42 school curriculum.

## Project Overview

The goal of the `ft_printf` project is to recreate the standard C library function `printf`, with support for variable argument lists and a range of format specifiers. This project helps develop a deeper understanding of variadic functions, memory management, and string formatting in C.

## Current Status

This project is **in progress**. Below is an outline of the planned features and implementation details. Updates will be made as the project develops.

## Features (Planned)

- [ ] Support for mandatory conversion specifiers:
  - `%c` - Character
  - `%s` - String
  - `%p` - Pointer
  - `%d` and `%i` - Signed integers
  - `%u` - Unsigned integers
  - `%x` and `%X` - Hexadecimal (lowercase and uppercase)
  - `%%` - Percent sign
- [ ] Error-free memory management
- [ ] Compliance with 42's Norminette coding standard
- [ ] Makefile with standard rules:
  - `all`, `clean`, `fclean`, `re`, and `bonus`
- [ ] (Optional) Bonus features:
  - Field width, precision, and flags support

## Directory Structure

```
ft_printf/
├── Makefile           # Builds the library
├── ft_printf.h        # Header file with function prototypes
├── ft_printf.c        # Core implementation of ft_printf
├── conversions.c      # Format specifier handling
├── utils.c            # Helper functions
└── README.md          # Project documentation (this file)
```

## How to Use

### Compilation

To build the project, run:

```bash
make
```

This will generate the `libftprintf.a` library.

### Example Usage

```c
#include "ft_printf.h"

int main() {
    ft_printf("Hello, %s! The number is %d.\n", "world", 42);
    return 0;
}
```

Compile your program with the `libftprintf.a` library:

```bash
gcc -o example example.c libftprintf.a
```

### Cleaning Up

To remove object files, run:

```bash
make clean
```

To remove the library and object files, run:

```bash
make fclean
```

## Testing

Tests are being developed to ensure `ft_printf` matches the behavior of the standard `printf` function. A testing framework or custom test cases may be added later.

## License

This project is part of the 42 school curriculum and follows its academic rules. Please refrain from unauthorized copying or sharing.

---

_This README will be updated as the project progresses._
