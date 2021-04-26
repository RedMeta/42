# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asinamet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/11 11:47:59 by asinamet          #+#    #+#              #
#    Updated: 2021/01/11 15:26:52 by asinamet         ###   ########.fr        #
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
		./ft_strlcpy.c		\
 		./ft_strlen.c 		\
		./ft_strncmp.c		\
		./ft_strchr.c		\
		./ft_strrchr.c		\
 		./ft_tolower.c 		\
 		./ft_toupper.c 		\
		./ft_strlcat.c		\
		./ft_strdup.c		\
		./ft_calloc.c		\
		./ft_strnstr.c		\
		./ft_substr.c		\
		./ft_strjoin.c		\
		./ft_strtrim.c		\
		./ft_split.c		\
		./ft_putchar_fd.c	\
		./ft_putstr_fd.c	\
		./ft_itoa.c			\
		./ft_strmapi.c		\
		./ft_putchar_fd.c	\
		./ft_putstr_fd.c	\
		./ft_putendl_fd.c	\
		./ft_putnbr_fd.c	\
		ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c 		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstiter.c		\
		ft_lstmap.c			\

OBJS = $(SRC:.c=.o)

HDRS = libft.h

RM	= rm -f

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror -I $(HDRS) $(SRC) 
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	/bin/rm -f $(NAME) ${BONUS_OBJS}

re: fclean all

.PHONY:		all clean fclean re bonus