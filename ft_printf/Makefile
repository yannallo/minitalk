NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I./

HEADER = ft_printf.h
SRC = src/ft_printf.c src/ft_putchar.c src/ft_putstr.c src/ft_putnbr.c src/ft_putnbr_base.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c Makefile $(HEADER)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
