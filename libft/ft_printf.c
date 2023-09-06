/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:55:44 by scharuka          #+#    #+#             */
/*   Updated: 2023/05/18 22:24:11 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_percent(const char *fm, va_list vl, int *len, int i)
{
	if (fm[i] == 'c')
		*len += ft_pfputchar (va_arg (vl, int));
	else if (fm[i] == 's')
		*len += ft_pfputstr (va_arg (vl, char *));
	else if (fm[i] == 'p')
	{
		*len += write(1, "0x", 2);
		ft_pfptr(va_arg(vl, uintptr_t), 16, "0123456789abcdef", len);
	}
	else if (fm[i] == 'd' || fm[i] == 'i')
		ft_pfputnbr(va_arg(vl, int), 10, "0123456789", len);
	else if (fm[i] == 'u')
		ft_pfputnbr(va_arg(vl, unsigned int), 10, "0123456789", len);
	else if (fm[i] == 'x')
		ft_pfputnbr(va_arg(vl, unsigned int), 16, "0123456789abcdef", len);
	else if (fm[i] == 'X')
		ft_pfputnbr(va_arg(vl, unsigned int), 16, "0123456789ABCDEF", len);
	else if (fm[i] == '%')
		*len += write(1, "%%", 1);
	else
		return (0);
	return (1);
}

int	ft_printf(const char *fm, ...)
{
	va_list		vl;
	int			i;
	int			len;

	va_start(vl, fm);
	i = 0;
	len = 0;
	while (fm[i])
	{
		if (fm[i] != '%')
		{
			len += write (1, &fm[i], 1);
		}
		else
		{
			i += check_percent(fm, vl, &len, i + 1);
		}
		i++;
	}
	va_end(vl);
	return (len);
}
