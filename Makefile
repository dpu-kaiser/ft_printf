NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_FILES = ft_printf.c ft_printnbr.c ft_printhex.c ft_printaddr.c
OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

%.o: %.c
	$(CC) -I. $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
