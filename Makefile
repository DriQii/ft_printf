CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = printftest

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

all = $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) src/ft_printf.c -I include -L lib -l ft