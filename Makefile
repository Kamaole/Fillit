# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmatos <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/07 16:49:12 by rmatos            #+#    #+#              #
#    Updated: 2016/10/07 17:02:35 by rmatos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = ./include/
SRC = ./src/*.c libft/*.c
OBJS = $(SRC:.c=.o)
NAME = fillit

all: $(NAME)
	@echo Simple Compiler

love: all

norm:
	norminette $(S)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) 

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) *.o *~ $(NAME)

depend: $(SRC)
	makedepend $(INCLUDEs) $^

.PHONY: all clean fclean re norm
