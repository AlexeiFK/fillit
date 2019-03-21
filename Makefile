# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/15 13:19:37 by rjeor-mo          #+#    #+#              #
#    Updated: 2019/03/21 18:32:26 by rjeor-mo         ###   ########.fr        #
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
	 $(SDIR)valid.c \
	 $(SDIR)get_next_line.c \
	 $(SDIR)num_to_fig.c \
	 $(SDIR)map.c

OBJ = $(subst .c,.o,$(subst src/,,$(SRC)))

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -I$(SDIR) -Ilibft/

all: $(NAME)

clean:
	$(RM) $(OBJ)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
