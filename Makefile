NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_FILES = src/ft_printf.c
OBJ_FILES = $(SRC_FILES:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): libft $(OBJ_FILES)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ_FILES)

libft:
	make -C libft

clean:
	rm -f $(OBJ_FILES)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re libft
