/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:19:44 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/07 23:38:59 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_floodfill(char **map, int r, int c, t_info *game)
{
	if (map[r][c] == 'F')
		return ;
	map[r][c] = 'F';
	if (map[r + 1][c] != '1' && map[r + 1][c] != 'F' && r < game->height)
		ft_floodfill(map, r + 1, c, game);
	if (map[r - 1][c] != '1' && map[r - 1][c] != 'F' && r >= 0)
		ft_floodfill(map, r - 1, c, game);
	if (map[r][c - 1] != '1' && map[r][c - 1] != 'F' && c >= 0)
		ft_floodfill(map, r, c - 1, game);
	if (map[r][c + 1] != '1' && map[r][c + 1] != 'F' && c < game->width)
		ft_floodfill(map, r, c + 1, game);
}

static void	ft_afterfill(char **map, t_info *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (map[i][j] != '1' && map[i][j] != 'F' && map[i][j] != '0')
				ft_error();
			j++;
		}
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_check_map_utils(t_info *game)
{
	char	**tmap;
	int		i;
	int		j;

	tmap = malloc((game->height) * sizeof(char *));
	i = 0;
	while (i < game->height)
	{
		tmap[i] = malloc((game->width) * sizeof(char));
		j = 0;
		while (j < game->width)
		{
			tmap[i][j] = game->map.map[i][j];
			j++;
		}
		i++;
	}
	ft_floodfill(tmap, game->py, game->px, game);
	ft_afterfill(tmap, game);
}
