/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:33:52 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/05 20:45:00 by scharuka         ###   ########.fr       */
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

typedef struct s_img
{
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	void	*grass;
}			t_img;

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
}			t_map;

typedef struct s_info
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	map;
}			t_info;

int	ft_lenline(int fd);
int	ft_numline(int fd, int mwidth);
void	ft_sizeanderror(t_info *game, char **argv);
#endif
