/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeanderror.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:09:51 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/07 23:42:59 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_sizeanderror(t_info *game, char **argv)
{
	int		fd;
	char	*test;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error: open failed\n");
		exit(EXIT_FAILURE);
	}
	test = ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]));
	if (test == NULL || ft_strlen(test) != 4)
	{
		perror("Error: map need to be .ber\n");
		exit(EXIT_FAILURE);
	}
	game->width = ft_lenline(fd);
	game->height = ft_numline(fd, game->width);
}
