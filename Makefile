CC = gcc
CFLAGS = 
LIBFT = libft/*.c
SRC = src/*.c
NAME = Fillit

all:
	gcc -o $(NAME) $(LIBFT) $(SRC)

love: all

$(NAME): love
