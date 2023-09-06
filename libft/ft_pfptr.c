/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:26:26 by scharuka          #+#    #+#             */
/*   Updated: 2023/05/18 22:11:39 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_pfptr(uintptr_t n, uintptr_t base, char *table, int *len)
{
	if (n >= base)
		ft_pfptr(n / base, base, table, len);
	*len += write(1, &table[n % base], 1);
}
