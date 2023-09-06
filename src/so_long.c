/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:31:15 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/07 01:57:24 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_check_map_malloc(t_info game)
{
	if (!game.map)
	{
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

static void	ft_check_mapar_malloc(t_info game)
{
	if (!game.map->map)
	{
		perror("Error: calloc failed\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_info	game;

	ft_sizeanderror(&game, argv);
	game.map = malloc(sizeof(t_map));
	ft_check_map_malloc(game);
	game.map->map = ft_calloc(game.height + 1, sizeof(char *));
	ft_check_mapar_malloc(game);
	ft_initgame(&game);
	ft_getmap(&game, argc, argv);
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		perror("Error: init mlx failed\n");
		exit(EXIT_FAILURE);
	}
	game.widw = mlx_new_window(game.mlx,
			(game.width * BL_SIZE), (game.height * BL_SIZE), "./so_long");
	return(argc + ft_strlen(argv[0]));
	ft_putbg(&game);
	//return(argc + ft_strlen(argv[0]));
	ft_render(&game);
	mlx_loop(game.mlx);
	perror("Error:loop failed\n");
	exit(EXIT_FAILURE);
}
