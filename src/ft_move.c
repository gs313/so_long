/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:43:13 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/06 21:01:50 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_check_collect(t_info *game, int nx, int ny)
{
	char	tile;

	tile = game->map->map[nx][ny];
	if ((tile != 'E' || game->collected == game->map->coin) && tile != '1')
	{
		game->px = nx;
		game->py = ny;
	}
	else if (tile == 'E')
		ft_putstr_fd("Collect all the coin first\n", 1);
	if (tile == 'C')
	{
		game->collected++;
		game->map->map[game->py][game->px] = '0';
	}
}

void	ft_move(t_info *game, int nx, int ny, char d)
{
	mlx_put_image_to_window(game->mlx, game->widw,
		game->img->grass, (game->px * BL_SIZE), (game->py * BL_SISE));
	ft_check_collect(game, nx, ny);
	if (d == 'U')
		mlx_put_image_to_window(game->mlx, game->widw,
			game->img->player_up, (game->px * BL_SIZE), (game->py * BL_SISE));
	else if (d == 'D')
		mlx_put_image_to_window(game->mlx, game->widw,
			game->img->player_down, (game->px * BL_SIZE), (game->py * BL_SISE));
	else if (d == 'L')
		mlx_put_image_to_window(game->mlx, game->widw,
			game->img->player_left, (game->px * BL_SIZE), (game->py * BL_SISE));
	else if (d == 'R')
		mlx_put_image_to_window(game->mlx, game->widw, game->img->player_right,
			(game->px * BL_SIZE), (game->py * BL_SISE));
	mlx_do_sync(game->mlx);
	ft_printf("Move count:%d\n", game->move);
}
