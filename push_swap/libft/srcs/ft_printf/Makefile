#Name
NAME =				libftprintf.a

#Compiler
CC = 				gcc
CFLAGS = 			-Wall -Wextra -Werror
PREPROCESSOR_FLAG = -c
OUTPUT_FLAG =		-o
INCLUDES_FLAG = 	-I

#Ar
LIB =				ar -crs

#Shell
RM =				rm -rf

#Directories
DIR_SRCS = 		srcs/
DIR_INCLUDES = 	includes

#Files
SRCS_M =			ft_printf.c	\
					ft_modifiers.c

SRCS_S =			ft_spec_c.c	\
					ft_spec_s.c	\
					ft_spec_p.c	\
					ft_spec_d.c	\
					ft_spec_u.c	\
					ft_spec_x.c	\
					ft_spec_r.c

SRCS_U =			ft_isdigit.c	\
					ft_numlen_base.c	\
					ft_unumlen_base.c	\
					ft_ulnumlen_base.c	\
					ft_putchar_fd.c	\
					ft_putnbr_base_fd.c	\
					ft_putnbr_fd.c	\
					ft_putstr_fd.c	\
					ft_putstrlen_fd.c	\
					ft_putunbr_base_fd.c	\
					ft_putunbr_fd.c	\
					ft_special_atoi.c	\
					ft_strlen.c

OBJS = 				$(addprefix $(DIR_SRCS),$(addprefix main/, $(SRCS_M:.c=.o)) $(addprefix specs/, $(SRCS_S:.c=.o)) $(addprefix utils/, $(SRCS_U:.c=.o)))

%.o: %.c
	@$(CC) $(CFLAGS) $(PREPROCESSOR_FLAG) $(INCLUDES_FLAG) $(DIR_INCLUDES) $< $(OUTPUT_FLAG) $@

all: $(NAME)

#@$(CC) $(CFLAGS) $(INCLUDES_FLAG) $(DIR_INCLUDES) $(OBJS) $(OUTPUT_FLAG) $@
$(NAME): $(OBJS)
	@$(LIB) $(NAME) $(OBJS)
clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
