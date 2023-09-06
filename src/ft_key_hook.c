/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:44:30 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/06 16:12:08 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_checkwin(t_info *game)
{
	if (game->collected == game->map->coin)
	{
		ft_putstr_fd("You won with");
		ft_putnbr_fd(game->move);
		ft_putstr_fd("\n");
		exit(EXIT_SUCCESS);
	}
}

int		ft_key_hook(int key, t_info *game)
{
	if (key == ESC)
		ft_exit(game);
	else if (key == A)
	else if (key == S)
	else if (key == W)
	else if (key == D)
	if (game->map->map[px][py] == 'E')
		ft_checkwin(game);
	return (0);
}
