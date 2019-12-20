/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:32:53 by iounejja          #+#    #+#             */
/*   Updated: 2019/12/20 18:47:59 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	w_p_not_found(unsigned long nb, char c)
{
	int l_nb;

	l_nb = 0;
	if (c == 'p')
		ft_putstr("0x");
	ft_hex(nb, c);
	l_nb = (c == 'p') ? ft_len_hex(nb) + 2 : ft_len_hex(nb);
	g_count += l_nb;
}

void	found_precision_hex(unsigned long nb, int space, int zero, char c)
{
	int l_nb;

	l_nb = 0;
	if (g_justify == -1 || g_justify == 0)
		ft_print(space, ' ');
	if (c == 'p')
	{
		ft_putstr("0x");
		g_count += 2;
	}
	if (g_justify == 0 || g_precision > 0)
		ft_print(zero, '0');
	if (nb != 0)
		ft_hex(nb, c);
	if (g_justify == 1)
		ft_print(space, ' ');
}

void	found_width_hex(unsigned long nb, int space, char c)
{
	int l_nb;

	l_nb = ft_len_hex(nb);
	space = (g_width > l_nb) ? g_width - l_nb : 0;
	space = (c == 'p') ? space - 2 : space;
	if (g_justify == -1)
		ft_print(space, ' ');
	if (c == 'p')
	{
		ft_putstr("0x");
		g_count += 2;
	}
	if (g_justify == 0)
		ft_print(space, '0');
	ft_hex(nb, c);
	if (g_justify == 1)
		ft_print(space, ' ');
	space = (space < 0) ? 0 : space;
	g_count += l_nb + space;
}

void	ft_hex_flags(char c, va_list arg_list)
{
	unsigned long	nb;
	int				l_nb;
	int				space;
	int				zero;

	space = 0;
	zero = 0;
	if (c == 'p')
		nb = va_arg(arg_list, unsigned long);
	else
		nb = va_arg(arg_list, unsigned int);
	if (g_found == 'a')
		w_p_not_found(nb, c);
	else if (g_found == 'w')
		found_width_hex(nb, space, c);
	else
	{
		l_nb = (nb > 0) ? ft_len_hex(nb) : 0;
		zero = (g_precision > 0 && g_precision > l_nb) ? g_precision - l_nb : 0;
		space = (c == 'p') ? 2 : 0;
		space = (g_width > l_nb + zero + space) ?
		g_width - (l_nb + zero + space) : 0;
		found_precision_hex(nb, space, zero, c);
		g_count += l_nb + space + zero;
	}
}
