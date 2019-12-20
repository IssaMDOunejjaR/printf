/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:45:55 by iounejja          #+#    #+#             */
/*   Updated: 2019/12/20 18:45:46 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		i;
	va_list	arg_list;

	i = 0;
	g_count = 0;
	va_start(arg_list, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			g_count++;
		}
		else
			i = ft_check_flags(format, i + 1, arg_list);
		i++;
	}
	va_end(arg_list);
	return (g_count);
}
