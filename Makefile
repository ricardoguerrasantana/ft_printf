#	Makefile for ft_printf project

# Name of the library
NAME = libftprintf.a

# Test runner
TEST_RUNNER = test_runner

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
TEST_FLAGS = -lcriterion

# Directories
SRC_DIR = .
OBJ_DIR = obj
TEST_DIR = tests

# Files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
TESTS = $(wildcard $(TEST_DIR)/*.c)

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
	rm -rf $(OBJ) $(OBJ_DIR)

# Full clean rule
fclean: clean
	rm -f $(NAME) $(TEST_RUNNER)

# Remake rule
re: fclean all

# Test rule
test: $(TEST_RUNNER)
	./$(TEST_RUNNER)
	rm -f $(TEST_RUNNER)

$(TEST_RUNNER): $(NAME)
	$(CC) $(CFLAGS) $(TEST_FLAGS) -o $(TEST_RUNNER) $(TESTS) $(NAME)

.PHONY: all clean fclean re test
