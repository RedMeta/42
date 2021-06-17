# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asinamet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 12:00:41 by asinamet          #+#    #+#              #
#    Updated: 2021/05/24 12:00:43 by asinamet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME =	push_swap


SRCS_DIR = srcs

LIBFT_DIR = minilibft

OBJS_DIR = objs


SRCS_NAMES =	push_swap.c		\
				list.c			\
				dll.c			\
				dll_2.c			\
				moves.c			\
				support.c		\
				moment.c		\

LIBFT_NAMES =	ft_split.c		\
				ft_atoi.c		\
				ft_isdigit.c		\

OBJS_NAMES = $(SRCS_NAMES:.c=.o) $(LIBFT_NAMES:.c=.o)


SRCS_FILES = $(addprefix $(SRCS_DIR)/, $(SRCS_NAMES))

LIBFT_FILES = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAMES))

OBJS_FILES = $(addprefix $(OBJS_DIR)/, $(OBJS_NAMES))


SRCS = $(SRCS_FILES) $(LIBFT_FILES)

OBJS = $(OBJS_FILES)

HDRS =	./main.h

CC = gcc

CFLGS = -Wall -Wextra -Werror

CLEAN = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(HDRS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS): $(SRCS)
	-$(CC) $(CFLAGS) $(SRCS) -c
	mv *.o $(OBJS_DIR)

clean:
	$(CLEAN) $(OBJS)

fclean: clean
	$(CLEAN) $(NAME)

re: fclean all




