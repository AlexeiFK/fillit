# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/15 13:19:37 by rjeor-mo          #+#    #+#              #
#    Updated: 2019/03/15 14:21:52 by rjeor-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit
CC=gcc
CFLAGS=-Wall -Wextra -Werror

LDIR=libft/
SDIR=src/

RM= rm -f

SRC= $(SDIR)reader.c \
	 $(SDIR)writer.c \
	 $(SDIR)main.c \
	 $(SDIR)fillit.c \
	 $(SDIR)valid.c 
	 $(SDIR)get_next_line.c

OBJ = $(subst .c,.o,$(subst src/,,$(SRC)))

$(NAME): lib $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft

$(OBJ):
	$(CC) $(CFLAGS) -c $(SRC) -I$(SDIR) -Ilibft/

all: $(NAME)

lib:
	make -C libft

clean:
	$(RM) $(OBJ)
	make -C libft clean

fclean:
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
