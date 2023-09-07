/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:43:13 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/07 19:41:25 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_check_collect(t_info *game, int nx, int ny)
{
	char	tile;

	tile = game->map.map[ny][nx];
	if (tile == 'C')
	{
		game->collected++;
		game->map.map[ny][nx] = '0';
	}
	if ((tile != 'E' || game->collected >= game->map.coin) && tile != '1')
	{
		game->px = nx;
		game->py = ny;
	}
	else if (tile == 'E')
		ft_putstr_fd("Collect all the coin first\n", 1);
}

void	ft_move(t_info *game, int nx, int ny, char d)
{
	mlx_put_image_to_window(game->mlx, game->widw,
		game->img.grass, (game->px * BL_SIZE), (game->py * BL_SIZE));
	ft_check_collect(game, nx, ny);
	mlx_put_image_to_window(game->mlx, game->widw,
		game->img.grass, (game->px * BL_SIZE), (game->py * BL_SIZE));
	if (d == 'U')
		mlx_put_image_to_window(game->mlx, game->widw,
			game->img.player_up, (game->px * BL_SIZE), (game->py * BL_SIZE));
	else if (d == 'D')
		mlx_put_image_to_window(game->mlx, game->widw,
			game->img.player_down, (game->px * BL_SIZE), (game->py * BL_SIZE));
	else if (d == 'L')
		mlx_put_image_to_window(game->mlx, game->widw,
			game->img.player_left, (game->px * BL_SIZE), (game->py * BL_SIZE));
	else if (d == 'R')
		mlx_put_image_to_window(game->mlx, game->widw, game->img.player_right,
			(game->px * BL_SIZE), (game->py * BL_SIZE));
	mlx_do_sync(game->mlx);
	game->move++;
	ft_printf("Move count:%d coin collected = %d/%d\n ", game->move, game->collected, game->map.coin);
}
