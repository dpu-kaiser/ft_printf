NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_FILES = ft_printf.c

OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
