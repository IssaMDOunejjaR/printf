/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:38:38 by iounejja          #+#    #+#             */
/*   Updated: 2019/12/18 17:44:19 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(va_list arg_list)
{
	char	c;
	int		l_c;

	c = va_arg(arg_list, int);
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
