/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initgame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:37:13 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/07 19:47:59 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	void	ft_setimg2(t_info *game)
{
	char	*path;
	// int		iwidth;
	// int		iheight;

	path = ft_strdup("game_img/TexturedGrass.xpm");
	game->img.grass = mlx_xpm_file_to_image(
			game->mlx, path, NULL, NULL);
	free(path);
	path = "game_img/Wall.xpm";
	game->img.wall = mlx_xpm_file_to_image(
			game->mlx, path, NULL, NULL);
	path = "game_img/coin.xpm";
	game->img.coin = mlx_xpm_file_to_image(
			game->mlx, path, NULL, NULL);
	path = "game_img/exit.xpm";
	game->img.exit = mlx_xpm_file_to_image(
			game->mlx, path, NULL, NULL);
}

static void	ft_setimg(t_info *game)
{
	// char	*path;
	// int		iwidth;
	// int		iheight;

	// path = "game_img/front_stand.xpm";
	// game->img.player_down = mlx_xpm_file_to_image(
	// 		game->mlx, path, &iwidth, &iheight);
	// path = "game_img/Back_stand.xpm";
	// game->img.player_up = mlx_xpm_file_to_image(
	// 		game->mlx, path, &iwidth, &iheight);
	// path = "game_img/Right1.xpm";
	// game->img.player_right = mlx_xpm_file_to_image(
	// 		game->mlx, path, &iwidth, &iheight);
	// path = "game_img/Left1.xpm";
	// game->img.player_left = mlx_xpm_file_to_image(
	// 		game->mlx, path, &iwidth, &iheight);
	ft_setimg2(game);
}

void	ft_initgame(t_info *game)
{
	// t_img	*img;

	// img = malloc(sizeof(t_img));
	// if (!img)
	// {
	// 	perror("Error: mallloc failed");
	// 	exit(EXIT_FAILURE);
	// }
	// game->img = img;
	ft_setimg(game);
	game->collected = 0;
	game->move = 0;
}
