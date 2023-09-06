/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:55:25 by scharuka          #+#    #+#             */
/*   Updated: 2023/05/18 22:33:43 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

int		ft_printf(const char *f, ...);
int		ft_pfputchar(char c);
size_t	ft_pfstrlen(const char *s);
int		ft_pfputstr(char *str);
void	ft_pfputnbr(int64_t n, int base, char *table, int *len);
void	ft_pfptr(uintptr_t n, uintptr_t base, char *table, int *len);

#endif
