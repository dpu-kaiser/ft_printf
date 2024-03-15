NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_FILES = src/ft_printf.c src/ft_printnbr.c src/ft_printhex.c src/ft_printaddr.c
OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
