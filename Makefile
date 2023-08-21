์์ืNAME = so_long
INCLUDES = -I/opt/X11/include -Imlx
SOURCES = test1.c
CFLAGS = -Wall -Wextra -Werror -g 

CC = gcc
 
MLX_FLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit

OBJ	:= $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C mlx/
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(MLX_FLAG)

norm:
	norminette -R checkforbiddensourceheader $(SOURCES)
	norminette -R checkdefine src/solong.h
clean:
	@make clean -C mlx/
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re norm
