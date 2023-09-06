/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:43:13 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/06 16:28:28 by scharuka         ###   ########.fr       */
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
		ft_putstr_fd("Collect all the coin first");
	if (tile == 'C')
	{

	}
	mlx_do_sy
}
void		ft_move(t_info *game, int nx, int ny)
{
	mlx_put_image_to_window(game->mlx, game->widw,
		game->img->grass, (game->px * BL_SIZE), (game->py * BL_SISE));

}
