/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:35:36 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/06 13:31:07 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_put(t_info *game, char tile, int x, int y)
{
	if (tile == 'P')
	{
		mlx_put_image_to_window(game->mxl, game->widw,
			game->img->player_down, (x * BL_SIZE), (y * BL_SIZE));
		game->px = x;
		game->py = y;
	}
	else if (tile == 'C')
		mlx_put_image_to_window(game->mxl, game->widw,
			game->img->coin, (x * BL_SIZE), (y * BL_SIZE));
	else if (tile == 'E')
		mlx_put_image_to_window(game->mxl, game->widw,
			game->img->exit, (x * BL_SIZE), (y * BL_SIZE));
	else if (tile == '1')
		mlx_put_image_to_window(game->mxl, game->widw,
			game->img->wall, (x * BL_SIZE), (y * BL_SIZE));
}

void	ft_exit(t_info *game)
{
	mlx_destroy_window(game->mlx, game->widw)
	ft_putstr_fd("Bye ~ ! \n");
	exit(EXIT_SUCCESS);
}

void	ft_render(t_info *game)
{
	int	x;
	int	y;

	y = 0;
	while ( y < game->map->height)
	{
		x = 0;
		while ( x < game->map->width)
		{
			ft_put(game, game->map->map[x][y], x, y);
		}
	}
	mlx_hook(game->widw, 17, 1L << 2, ft_exit, data);
	mlx_key_hook(game->widw, ft_key_hook, data);
	return (0);
}
