/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:44:30 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/07 23:31:11 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_freegame(t_info *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
	mlx_destroy_image(game->mlx, game->img.coin);
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.player_down);
	mlx_destroy_image(game->mlx, game->img.player_left);
	mlx_destroy_image(game->mlx, game->img.player_right);
	mlx_destroy_image(game->mlx, game->img.player_up);
	mlx_destroy_window(game->mlx, game->widw);
}

static void	ft_checkwin(t_info *game)
{
	ft_printf("You won with %d move\n", game->move);
	ft_freegame(game);
	exit(EXIT_SUCCESS);
}

int	ft_key_hook(int key, t_info *game)
{
	if (key == ESC)
		ft_exit(game);
	else if (key == A)
		ft_move(game, (game->px - 1), game->py, 'L');
	else if (key == S)
		ft_move(game, game->px, (game->py + 1), 'D');
	else if (key == W)
		ft_move(game, game->px, (game->py - 1), 'U');
	else if (key == D)
		ft_move(game, (game->px + 1), game->py, 'R');
	if (game->map.map[game->py][game->px] == 'E')
		ft_checkwin(game);
	return (0);
}
