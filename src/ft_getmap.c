/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:00:54 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/05 21:30:42 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_argcerror(int argc)
{
	if (argc != 2)
	{
		perror("Error: map input is not one");
		exit(EXIT_FAILURE);
	}
}

static void	ft_check_map (t_info *game)
{
	return ;
}

void	ft_getmap(t_info *game, int argc, char **argv)
{
	int		i;
	int		fd;
	int		reading;
	char	ch[2];

	ft_argcerror(argc);
	i = 0;
	ch[1] = '\0';
	fd = open(argv[1], O_RDONLY);
	reading = read(fd, ch, 1);
	while (reading)
	{
		if (ch[0] != '\n' && ch[0] != '\0')
			game->map->map[i] = ft_strjoin(game->map->map[i], ch);
		else
			i++;
		reading = read(fd, ch, 1);
	}
}
