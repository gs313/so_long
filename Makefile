# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 15:18:47 by scharuka          #+#    #+#              #
#    Updated: 2023/09/05 16:26:52 by scharuka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
INCLUDES = -I/opt/X11/include -Imlx
SOURCES =	\
			src/so_long.c \
			src/ft_sizeanderror.c\
			src/ft_lenline.c \
			src/ft_numline.c \

CFLAGS = -Wall -Wextra -Werror -g

CC = gcc

MLX_FLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit

MLX_LIB = mlx/libmlx.a

LIBFT_LIB = libft/libft.a

OBJ	:= $(SOURCES:.c=.o)

all: $(NAME)


%.o : %.c
	@$(CC) $(CFLAGGS) -Imlx -c -o $@ $<

$(NAME): $(OBJ)
	@make -C mlx/ all
	@make -C libft/
	$(CC) $(CFLAGS) $(MLX_FLAG) $(OBJ) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)

norm:
	norminette -R checkforbiddensourceheader $(SOURCES)
	norminette -R checkdefine src/solong.h
clean:
	@make clean -C mlx/
	@make clean -C libft/
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@make -C mlx/ clean
	@make -C libft/ fclean

re: fclean all

.PHONY: clean fclean all re norm
