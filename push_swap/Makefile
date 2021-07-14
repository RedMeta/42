#Names
NAME_PS = 				push_swap

#Compiler
CC = 					gcc
CFLAGS = 				-Wall -Wextra -Werror -g
PREPROCESSOR_FLAG = 	-c
OUTPUT_FLAG =			-o
INCLUDES_FLAG =			-I

#Make
MAKE = 					make -C
MAKE_CLEAN = 			make clean -C
MAKE_FCLEAN = 			make fclean -C

#Shell
CP =					cp
RM =					rm -rf

#Directories
DIR_SRCS_PS = 			srcs/push_swap
DIR_SRCS_SD = 			srcs/share
DIR_INCLUDES = 			includes
DIR_LIBFT = 			libft

#Libs
LIBFT = 				libft.a

#Files

NAME_SRCS_PS = 		push_swap.c 			\
					sort_less_five.c	 	\
					sort.c 					\
					lis.c 					\
					clean_stack_a.c 		\
					operations_loops.c 		\
					min_moves.c				\
					operations_push.c 		\
					operations_swap.c 		\
					operations_rotate.c 	\
					operations_rev_rotate.c 

NAME_SRCS_SD =		initialize.c 			\
					take_numbers.c 			\
					index.c 				\
					find_limits.c 			\
					print_gui.c 			\
					exit_manager.c 			\
					print_stacks_and_counts.c

SRCS_PS =				$(addprefix $(DIR_SRCS_PS)/, $(NAME_SRCS_PS))
SRCS_SD =				$(addprefix $(DIR_SRCS_SD)/, $(NAME_SRCS_SD))

OBJS_PS = 				$(SRCS_PS:.c=.o)
OBJS_SD = 				$(SRCS_SD:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES_FLAG) $(DIR_INCLUDES) $(PREPROCESSOR_FLAG) $< $(OUTPUT_FLAG) $@

all: $(NAME_PS)


$(NAME_PS):	$(OBJS_PS) $(OBJS_SD) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_PS) $(OBJS_SD) $(LIBFT) $(OUTPUT_FLAG) $(NAME_PS) 

$(LIBFT):
	@$(MAKE) $(DIR_LIBFT)
	@$(CP) $(DIR_LIBFT)/$(LIBFT) .

clean:
	@$(RM) $(OBJS_PS) $(OBJS_SD) $(LIBFT)
	@$(MAKE_CLEAN) $(DIR_LIBFT)

fclean: clean
	@$(RM) $(NAME_PS)
	@$(MAKE_FCLEAN) $(DIR_LIBFT)

re: fclean all

.PHONY: all norminette clean fclean re
