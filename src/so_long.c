/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:31:15 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/05 21:00:34 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_info	game;

	ft_sizeanderror(&game, argv);
	game.map.map = ft_calloc(game.map.height + 1, sizeof(char *));
	if (!map.map)
	{
		perror("Error: calloc failed");
		exit(EXIT_FAILURE);
	}
	ft_initgame(game);
	ft_getmap(&game, ar)
	game.mlx = mlx_init();
	mlx_loop(mlx);
}
