/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:33:52 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/07 21:37:57 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BL_SIZE 32
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

typedef struct s_img
{
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	void	*grass;
	void	*wall;
	void	*coin;
	void	*exit;
}			t_img;

typedef struct s_map
{
	char	**map;
	int		coin;
	int		exit;
}			t_map;

typedef struct s_info
{
	void	*mlx;
	void	*widw;
	int		check_p;
	int		collected;
	int		move;
	int		px;
	int		py;
	int		width;
	int		height;
	t_img	img;
	t_map	map;
}			t_info;

int		ft_lenline(int fd);
int		ft_numline(int fd, int mwidth);
void	ft_sizeanderror(t_info *game, char **argv);
void	ft_initgame(t_info *game);
void	ft_getmap(t_info *game, int argc, char **argv);
void	ft_render(t_info *game);
void	ft_putbg(t_info *game);
int		ft_exit(t_info *game);
void	ft_move(t_info *game, int nx, int ny, char d);
int		ft_key_hook(int key, t_info *game);
void	ft_freegame(t_info *game);
void	ft_error(void);
void	ft_check_map_utils(t_info *game);

#endif
