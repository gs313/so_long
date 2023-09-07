/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:00:54 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/07 22:46:07 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_check_tile(char a, int x, int y, t_info *game)
{
	int	h;
	int	w;

	h = game->height;
	w = game->width;
	if (a != '0' && a != '1' && a != 'C' && a != 'P' && a != 'E')
	{
		perror("Error: some tiles in this map is invalid\n");
		exit(EXIT_FAILURE);
	}
	if ((x == 0 || y == 0 || x == w - 1 || y == h - 1) && (a != '1'))
	{
		perror("Error: map need to be surround by walls\n");
		exit(EXIT_FAILURE);
	}
	if (a == 'C')
		game->map.coin++;
	else if (a == 'P')
	{
		game->check_p++;
		game->px = x;
		game->py = y;
	}
	else if (a == 'E')
		game->map.exit++;
}

static void	ft_check_content(t_info *game)
{
	if (game->check_p != 1)
		perror("Error:this can only be single player game\n");
	else if (game->map.exit != 1)
		perror("Error: there should be one and only exit in this file\n");
	else if (game->map.coin == 0)
		perror("Error: ther are not collectable on the map\n");
	else
	{
		ft_check_map_utils(game);
		return ;
	}
	exit(EXIT_FAILURE);
}

static void	ft_check_map(t_info *game)
{
	int	x;
	int	y;

	game->map.coin = 0;
	game->check_p = 0;
	game->map.exit = 0;
	y = 0;
	while (y < (game->height))
	{
		if (ft_strlen(game->map.map[y]) != (size_t)game->width)
		{
			perror("Error: map boarder has to be even\n");
			exit(EXIT_FAILURE);
		}
		x = 0;
		while (x < game->width)
		{
			ft_check_tile(game->map.map[y][x], x, y, game);
			x++;
		}
		y++;
	}
	return ;
}

void	ft_getmap(t_info *game, int argc, char **argv)
{
	int		i;
	int		fd;
	int		reading;
	char	ch[2];

	if (argc != 2)
		ft_error();
	i = 0;
	ch[1] = '\0';
	fd = open(argv[1], O_RDONLY);
	reading = read(fd, ch, 1);
	game->map.map[i] = ft_calloc(1, sizeof(char *));
	while (reading == 1)
	{
		if (ch[0] != '\n' && ch[0] != '\0')
			game->map.map[i] = ft_strjoin(game->map.map[i], ch);
		else
		{
			i++;
			game->map.map[i] = ft_calloc(1, sizeof(char *));
		}
		reading = read(fd, ch, 1);
	}
	ft_check_map(game);
	ft_check_content(game);
}
