/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:44:43 by scharuka          #+#    #+#             */
/*   Updated: 2023/09/07 23:38:38 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	char	*ans;

	if (!s1 || !s2)
		return (0);
	i = (size_t)ft_strlen(s1) + (size_t)ft_strlen(s2);
	ans = (char *) malloc(sizeof(char) * (i + 1));
	if (! ans)
		return (NULL);
	ft_memcpy(ans, s1, (size_t)ft_strlen(s1));
	ft_memcpy(ans + (size_t)ft_strlen(s1), s2, (size_t)ft_strlen(s2));
	ans[i] = '\0';
	if (s1)
		free(s1);
	return (ans);
}
