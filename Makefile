CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = printftest

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) -o $(NAME) src/ft_printf.c -I include -L lib -l ft

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

