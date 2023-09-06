/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:31:15 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/06 11:40:36 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_info	game;

	ft_sizeanderror(&game, argv);
	game.map->map = ft_calloc(game.map->height + 1, sizeof(char *));
	if (!map->map)
	{
		perror("Error: calloc failed\n");
		exit(EXIT_FAILURE);
	}
	ft_initgame(&game);
	ft_getmap(&game, argc, argv);
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		perror("Error: init mlx failed\n");
		exit(EXIT_FAILURE);
	}
	game.widw = mlx_new_window(game.mlx,
			game.map->width, game.map->height, "./so_long");
	ft_putbg(&game);
	ft_render(&game);
	mlx_loop(game.mlx);
	perror("Error:loop failed\n");
	exit(EXIT_FAILURE);
}
