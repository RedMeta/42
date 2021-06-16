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

NAME =	push_swap.out

SRCS =	./main.c \
	./list.c

OBJS =	$(SRCS:.c=.o)

HDRS =	./main.h

CC =	gcc

CFLGS =	-Wall -Wextra -Werror

CLEAN = rm -rf

.PHONY = all

all: $(NAME)

$(OBJS): 
	$(CC) $(CFLAGS) $(SRCS) -c

$(NAME): $(OBJS) $(HDRS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	$(CLEAN) $(OBJS)

fclean: clean
	$(CLEAN) $(NAME)

re: fclean all




