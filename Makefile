# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cipmures <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/12 15:59:47 by cipmures          #+#    #+#              #
#    Updated: 2017/02/13 17:49:17 by cipmures         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = read.c \
	  additionals.c \
	  backt.c \
	  map_functions.c \
	  main.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I. -c $(SRC)
	$(CC) $(CFLAGS) -I. $(OBJ) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
