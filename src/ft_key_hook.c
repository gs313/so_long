/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:44:30 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/06 21:27:14 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_checkwin(t_info *game)
{
	if (game->collected == game->map->coin)
	{
		ft_printf("You won with %d move\n", game->move);
		exit(EXIT_SUCCESS);
	}
}

int	ft_key_hook(int key, t_info *game)
{
	if (key == ESC)
		ft_exit(game);
	else if (key == A)
		ft_move(game, (game->px - BL_SIZE), game->py, 'L');
	else if (key == S)
		ft_move(game, game->px, (game->py + BL_SIZE), 'L');
	else if (key == W)
		ft_move(game, (game->px + BL_SIZE), game->py, 'L');
	else if (key == D)
		ft_move(game, game->px, (game->py - BL_SIZE), 'L');
	if (game->map->map[game->px][game->py] == 'E')
		ft_checkwin(game);
	return (0);
}
