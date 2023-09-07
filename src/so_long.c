/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:31:15 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/07 23:29:06 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_check_mapar_malloc(t_info *game)
{
	if (!game->map.map)
	{
		perror("Error: calloc failed\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_info	game;
	t_map	map;

	ft_sizeanderror(&game, argv);
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		perror("Error: init mlx failed\n");
		exit(EXIT_FAILURE);
	}
	map.map = ft_calloc((game.height), sizeof(char *));
	game.map = map;
	ft_check_mapar_malloc(&game);
	ft_initgame(&game);
	ft_getmap(&game, argc, argv);
	game.widw = mlx_new_window(game.mlx,
			(game.width * BL_SIZE), (game.height * BL_SIZE), "./so_long");
	ft_putbg(&game);
	ft_render(&game);
	mlx_loop(game.mlx);
	perror("Error:loop failed\n");
	ft_freegame(&game);
	exit(EXIT_FAILURE);
}
