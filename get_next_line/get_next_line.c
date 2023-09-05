/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:01:40 by scharuka          #+#    #+#             */
/*   Updated: 2022/12/29 15:47:19 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_stbuff(char *stbuff)
{
	if (stbuff != NULL)
		free(stbuff);
	return (NULL);
}

void	change_buf(char *buf, char *next)
{
	int	i;

	i = 0;
	while (next[i] != '\0')
	{
		buf[i] = next[i];
		i++;
	}
	while (i <= BUFFER_SIZE)
	{
		buf[i] = '\0';
		i++;
	}
}

char	*check_stbuff(char *stbuff, char *line)
{
	char	*tmp;
	char	*nextline;

	if (stbuff != NULL)
	{
		nextline = ft_strchr(stbuff, '\n');
		if (nextline)
		{
			tmp = ft_substr(stbuff, 0, ((nextline - stbuff) + 1));
			line = ft_strjoin_f(line, tmp);
			free(tmp);
			change_buf(stbuff, nextline + 1);
		}
		else
		{
			line = ft_strjoin_f(line, stbuff);
		}
	}
	return (line);
}

char	*initial(char **stbuff)
{
	char	*line;

	line = (char *)malloc(sizeof(char));
	line[0] = '\0';
	if (*stbuff == NULL)
	{
		*stbuff = malloc(BUFFER_SIZE + 1);
		if (*stbuff != NULL)
			**stbuff = '\0';
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stbuff;
	char		*line;
	int			byte;

	byte = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = initial(&stbuff);
	while (1)
	{
		line = check_stbuff(stbuff, line);
		if (stbuff == NULL || ft_strchr(line, '\n') || byte == 0)
			break ;
		byte = read(fd, stbuff, BUFFER_SIZE);
		if (byte < 0)
			return (NULL);
		stbuff[byte] = '\0';
	}
	if (line[0] == '\0')
		line = free_stbuff(line);
	if (line == NULL || byte == 0)
		stbuff = free_stbuff(stbuff);
	return (line);
}
