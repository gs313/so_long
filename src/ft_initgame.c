/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initgame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:37:13 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/07 22:07:02 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	void	ft_setimg2(t_img *img, t_info *game)
{
	char	*path;
	int		iwidth;
	int		iheight;

	path = "game_img/TexturedGrass.xpm";
	img->grass = mlx_xpm_file_to_image(
			game->mlx, path, &iwidth, &iheight);
	path = "game_img/Wall.xpm";
	img->wall = mlx_xpm_file_to_image(
			game->mlx, path, &iwidth, &iheight);
	path = "game_img/coin.xpm";
	img->coin = mlx_xpm_file_to_image(
			game->mlx, path, &iwidth, &iheight);
	path = "game_img/exit.xpm";
	img->exit = mlx_xpm_file_to_image(
			game->mlx, path, &iwidth, &iheight);
}

static void	ft_setimg(t_img *img, t_info *game)
{
	char	*path;
	int		iwidth;
	int		iheight;

	path = "game_img/front_stand.xpm";
	img->player_down = mlx_xpm_file_to_image(
			game->mlx, path, &iwidth, &iheight);
	path = "game_img/Back_stand.xpm";
	img->player_up = mlx_xpm_file_to_image(
			game->mlx, path, &iwidth, &iheight);
	path = "game_img/Right1.xpm";
	img->player_right = mlx_xpm_file_to_image(
			game->mlx, path, &iwidth, &iheight);
	path = "game_img/Left1.xpm";
	img->player_left = mlx_xpm_file_to_image(
			game->mlx, path, &iwidth, &iheight);
	ft_setimg2(img, game);
}

void	ft_initgame(t_info *game)
{
	t_img	img;

	ft_setimg(&img, game);
	game->img = img;
	game->collected = 0;
	game->move = 0;
}
