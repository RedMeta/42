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

SRC		= $(wildcard ./utils/*.c) $(wildcard ./put/*.c) ft_printf.c

OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
HEADER	= ft_printf.h
CLEAN	= rm -f

$(NAME): $(OBJ)
	ar rcs $@ $^

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $@

clean:
	$(CLEAN) $(OBJ)

fclean:
	$(CLEAN) $(OBJ) $(NAME) a.out

main: $(NAME)

	$(CC) $(CFLAGS) main.c $(NAME)

re: fclean all