# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmangola <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/11 11:47:59 by dmangola          #+#    #+#              #
#    Updated: 2021/01/11 15:26:52 by dmangola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	./ft_atoi.c 		\
 		./ft_bzero.c 		\
 		./ft_isalnum.c 		\
 		./ft_isalpha.c 		\
 		./ft_isascii.c 		\
 		./ft_isdigit.c 		\
 		./ft_isprint.c 		\
 		./ft_memccpy.c 		\
 		./ft_memchr.c 		\
 		./ft_memcmp.c 		\
 		./ft_memcpy.c 		\
 		./ft_memmove.c 		\
 		./ft_memset.c 		\
 		./ft_strlen.c 		\
 		./ft_tolower.c 		\
 		./ft_toupper.c 		\

OBJS = $(SRC:.c=.o)

HDRS = libft.h

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror -I $(HDRS) $(SRC) 
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all