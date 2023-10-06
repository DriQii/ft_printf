
NAME = ft_printf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = src/ft_printf.c \
	src/utils.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -I include -c $< -o $@

$(NAME) : $(OBJ)
	cp lib/libft.a .
	mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ) $(BONUSOBJ)

fclean : clean
	rm -rf $(NAME)

re : clean all
