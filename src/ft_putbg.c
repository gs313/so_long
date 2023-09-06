/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:40:50 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/06 21:24:23 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putbg(t_info *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->widgth)
		{
			mlx_put_image_to_window (game->mlx, game->widw,
				game->img->grass, (j * BL_SIZE), (i * BL_SIZE));
			j++;
		}
		i++;
	}
}
