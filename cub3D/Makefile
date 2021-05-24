NAME	=	cub3D

LIBFT	=	

GNL		=	

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f
			
LIBS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit

MLX		=	libmlx.dylib

SRCS	=	main.c

OBJ		=	$(SRCS:.c=.o)

%.o	:	%.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME)	:	$(MLX) $(OBJ)
#			make -C ./libft
#			make -C ./get_next_line
			$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(GNL) $(OBJ) $(LIBS)

$(MLX)	:
			@$(MAKE) -C mlx
			@mv mlx/$(MLX) .

debug	:	$(MLX) $(OBJ)
			make -C ./libft
			make -C ./get_next_line
			$(CC) -g $(CFLAGS) -o $(NAME) $(LIBFT) $(GNL) $(OBJ) $(LIBS)

all		:	$(NAME)

clean	:
			make -C mlx clean
			$(RM) $(OBJ)
			$(RM) libmlx.dylib
			$(RM) deepthought.bmp
			make clean -C ./libft
			make clean -C ./get_next_line

fclean	:	clean
			$(RM) $(NAME) $(MLX)
			make fclean -C ./libft
			make fclean -C ./get_next_line

re		:	fclean all

.PHONY	:	all clean fclean re
