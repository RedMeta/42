#Name
NAME = 				libft.a

#Compiler
CC = 				gcc
CFLAGS = 			-Wall -Wextra -Werror
PREPROCESSOR_FLAG = -c
OUTPUT_FLAG =		-o
INCLUDES_FLAG = 	-I

#Ar
LIB = 				ar -rcs
UNPACK =			ar -x

#Make
MAKE = 				make -C
MAKE_CLEAN = 		make clean -C
MAKE_FCLEAN = 		make fclean -C

#Shell
CP = 				cp
RM = 				rm -rf

#Directories
DIR_SRCS = 			srcs/
DIR_INCLUDES = 		includes/
DIR_TMP =			tmp/
DIR_PRINTF = 		$(DIR_SRCS)ft_printf/

#Libs
PRINTF = 		 	libftprintf.a

#Files
SRCS = 				$(shell find ./$(DIR_SRCS) -name ft_memset.c) \
					$(shell find ./$(DIR_SRCS) -name ft_bzero.c) \
					$(shell find ./$(DIR_SRCS) -name ft_memcpy.c) \
					$(shell find ./$(DIR_SRCS) -name ft_memccpy.c) \
					$(shell find ./$(DIR_SRCS) -name ft_memmove.c) \
					$(shell find ./$(DIR_SRCS) -name ft_memchr.c) \
					$(shell find ./$(DIR_SRCS) -name ft_memcmp.c) \
					$(shell find ./$(DIR_SRCS) -name ft_strlen.c) \
					$(shell find ./$(DIR_SRCS) -name ft_strcpy.c) \
					$(shell find ./$(DIR_SRCS) -name ft_strlcpy.c) \
					$(shell find ./$(DIR_SRCS) -name ft_strlcat.c) \
					$(shell find ./$(DIR_SRCS) -name ft_strchr.c) \
					$(shell find ./$(DIR_SRCS) -name ft_strrchr.c) \
					$(shell find ./$(DIR_SRCS) -name ft_strnstr.c) \
					$(shell find ./$(DIR_SRCS) -name ft_strncmp.c) \
					$(shell find ./$(DIR_SRCS) -name ft_strcmp.c) \
					$(shell find ./$(DIR_SRCS) -name ft_atoi.c) \
					$(shell find ./$(DIR_SRCS) -name ft_isalpha.c) \
					$(shell find ./$(DIR_SRCS) -name ft_isdigit.c) \
					$(shell find ./$(DIR_SRCS) -name ft_isalnum.c) \
					$(shell find ./$(DIR_SRCS) -name ft_isascii.c) \
					$(shell find ./$(DIR_SRCS) -name ft_isprint.c) \
					$(shell find ./$(DIR_SRCS) -name ft_toupper.c) \
					$(shell find ./$(DIR_SRCS) -name ft_tolower.c) \
					$(shell find ./$(DIR_SRCS) -name ft_calloc.c) \
					$(shell find ./$(DIR_SRCS) -name ft_strdup.c) \
					$(shell find ./$(DIR_SRCS) -name ft_substr.c) \
					$(shell find ./$(DIR_SRCS) -name ft_strjoin.c) \
					$(shell find ./$(DIR_SRCS) -name ft_strtrim.c) \
					$(shell find ./$(DIR_SRCS) -name ft_split.c) \
					$(shell find ./$(DIR_SRCS) -name ft_itoa.c) \
					$(shell find ./$(DIR_SRCS) -name ft_strmapi.c) \
					$(shell find ./$(DIR_SRCS) -name get_next_line.c) \
					$(shell find ./$(DIR_SRCS) -name get_next_line_utils.c) \
					$(shell find ./$(DIR_SRCS) -name ft_free_gnl_stdin.c) \
					$(shell find ./$(DIR_SRCS) -name ft_swap.c) \
					$(shell find ./$(DIR_SRCS) -name ft_dist.c) \
					$(shell find ./$(DIR_SRCS) -name ft_isspace.c) \
					$(shell find ./$(DIR_SRCS) -name ft_isspace_string.c) \
					$(shell find ./$(DIR_SRCS) -name ft_isdigit_string.c) \
					$(shell find ./$(DIR_SRCS) -name ft_mtxlen.c) \
					$(shell find ./$(DIR_SRCS) -name ft_if_free.c) \
					$(shell find ./$(DIR_SRCS) -name ft_tabcpy.c) \
					$(shell find ./$(DIR_SRCS) -name ft_free_mtx.c) \
					$(shell find ./$(DIR_SRCS) -name ft_atol.c)

OBJS = 				$(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES_FLAG) $(DIR_INCLUDES) $(PREPROCESSOR_FLAG) $< $(OUTPUT_FLAG) $@

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF)
	@$(LIB) $(NAME) $(OBJS)

$(PRINTF):
	@$(MAKE) $(DIR_PRINTF)
	@$(CP) $(DIR_PRINTF)/$(PRINTF) $(NAME)

clean:
	@$(RM) $(OBJS) $(PRINTF)
	@$(MAKE_CLEAN) $(DIR_PRINTF)

fclean: clean
	@$(RM) $(NAME) 
	@$(MAKE_FCLEAN) $(DIR_PRINTF)

re: fclean all

.PHONY: all clean fclean re
