NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -Iinclude

SRC = src/main.c src/utils.c src/init_cleanup.c src/stack.c src/stack_utils.c \
src/emit.c src/ops_swap.c src/ops_push.c src/ops_rotate.c src/ops_reverse.c \
src/parse.c src/validate_rank.c src/disorder.c src/sort_small.c \
src/sort_simple.c src/sort_medium.c src/sort_complex.c src/strategy.c \
src/bench.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re