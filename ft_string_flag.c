/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:48:07 by iounejja          #+#    #+#             */
/*   Updated: 2019/12/19 12:27:44 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	found_precision_s(char *str, int l_str)
{
	l_str = (g_precision >= ft_strlen(str)) ? ft_strlen(str) : g_precision;
	if (g_justify == -1)
		ft_print_spaces(l_str, ' ');
	if (g_justify == 0)
		ft_print_spaces(l_str, '0');
	ft_print_string(str, l_str, 0);
	if (g_justify == 1)
		ft_print_spaces(l_str, ' ');
	g_count += l_str;
}

void	found_width_s(char *str, int l_str)
{
	l_str = ft_strlen(str);
	if (g_justify == -1)
		ft_print_spaces(l_str, ' ');
	if (g_justify == 0)
		ft_print_spaces(l_str, '0');
	ft_print_string(str, l_str, 0);
	if (g_justify == 1)
		ft_print_spaces(l_str, ' ');
	g_count += l_str;
}

void	ft_string_flag(va_list arg_list)
{
	char	*str;
	int		l_str;

	l_str = 0;
	str = va_arg(arg_list, char *);
	if (!str)
		str = "(null)";
	if (g_found == 'a')
	{
		ft_putstr(str);
		g_count += ft_strlen(str);
	}
	else if (g_found == 'w')
		found_width_s(str, l_str);
	else
		found_precision_s(str, l_str);
}
