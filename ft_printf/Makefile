# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asinamet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/25 16:07:40 by asinamet          #+#    #+#              #
#    Updated: 2021/02/25 16:07:42 by asinamet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC		= $(wildcard ./utils/*.c) ft_printf.c main.c

OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -c -Wall -Wextra -Werror
HEADER	= ft_printf.h
CLEAN	= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(CLEAN) $(OBJ)

fclean:
	$(CLEAN) $(OBJ) $(NAME)

re: fclean all