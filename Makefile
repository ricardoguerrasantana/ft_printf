#	Makefile for ft_printf project
NAME = libftprintf.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
TEST_FLAGS = -lcriterion

# Source files
SRC = $(wildcard *.c)

# Object directory
OBJ_DIR = obj

# Object files
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# Default target
all: $(NAME)

# Build default target
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Create object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Build object files
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJ)

# Full clean rule
fclean: clean
	rm -f $(NAME)

# Remake rule
re: fclean all

# Test rule
test: $(NAME)
	$(CC) $(CFLAGS) $(TEST_FLAGS) -o tests/tests tests/*.c $(NAME)
	./tests/tests

.PHONY: all clean fclean re test
