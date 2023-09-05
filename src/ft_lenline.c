/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:37:58 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/05 12:46:08 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_lenline(int fd)
{
	char	ch[1];
	int		reading;
	int		len;

	len = 0;
	reading = read(fd, ch, 1);
	while (reading == 1)
	{
		if (ch[0] == '\n')
			break ;
		len++;
	}
	return (len);
}
