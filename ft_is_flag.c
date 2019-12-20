/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:59:52 by iounejja          #+#    #+#             */
/*   Updated: 2019/12/20 18:44:01 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_flag(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' ||
			c == 'u' || c == 'p' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
	{
		if (g_width - 1 > 0)
			ft_print(g_width - 1, ' ');
		g_count += (g_width == 0) ? g_width : g_width - 1;
		return (0);
	}
}
