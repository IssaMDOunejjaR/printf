/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:46:54 by iounejja          #+#    #+#             */
/*   Updated: 2019/12/20 18:47:42 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_print_perc(char c)
{
	int		l_c;

	if (g_found == 'a')
	{
		ft_putchar(c);
		g_count += 1;
	}
	else
	{
		l_c = 1;
		if (g_justify == -1)
			ft_print_spaces(l_c, ' ');
		if (g_justify == 0)
			ft_print_spaces(l_c, '0');
		ft_putchar(c);
		if (g_justify == 1)
			ft_print_spaces(l_c, ' ');
		g_count += 1;
	}
}

void			ft_flags(char c, va_list arg_list)
{
	if (c == 's')
		ft_string_flag(arg_list);
	else if (c == 'd' || c == 'i' || c == 'u')
		ft_integer_flag(c, arg_list);
	else if (c == 'c')
		ft_print_char(arg_list);
	else if (c == 'p' || c == 'x' || c == 'X')
		ft_hex_flags(c, arg_list);
	else if (c == '%')
		ft_print_perc('%');
}
