/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:52:28 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/05 13:05:40 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_numline(int fd, int mwidth)
{
	int		num;
	char	*line;

	num = 1;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) < mwidth
			|| (ft_strlen(line) == 1 && *line !='\n')
		{
			free(line);
			perror("map is stange!\n");
			exit(EXIT_FAILURE);
		}
		free(line);
		num++;
		line = get_next_line(fd);
	}
	return (num);
}
