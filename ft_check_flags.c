/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:46:45 by iounejja          #+#    #+#             */
/*   Updated: 2019/12/20 18:43:43 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_width(const char *format, int *index)
{
	g_found = 'w';
	while (format[*index] == '-')
		*index += 1;
	g_width = ft_get_digit(format, *index);
	while (format[*index] >= '0' && format[*index] <= '9')
		*index += 1;
	*index -= 1;
}

void	get_precision(const char *format, int *index, va_list arg_list)
{
	g_found = 'p';
	if (format[*index] == '*')
		g_precision = va_arg(arg_list, int);
	else
		g_precision = ft_get_digit(format, *index);
	while (ft_isdigit(format[*index]) || format[*index] == '*')
		*index += 1;
	*index -= 1;
}

int		check_format(const char *format, int index, va_list arg_list)
{
	while (ft_isprint(format[index]) &&
	!(ft_isalpha(format[index])) && format[index] != '%')
	{
		if (format[index] == '0' && (ft_isdigit(format[index + 1]) ||
		format[index + 1] == '*') && format[index - 1] != '-')
			g_justify = 0;
		if (format[index] == '.')
		{
			g_found = 'p';
			g_point = 1;
		}
		if ((ft_isdigit(format[index]) || format[index] == '-') && g_point == 0)
			get_width(format, &index);
		if (format[index] == '*' && g_point == 0)
		{
			g_found = 'w';
			g_width = va_arg(arg_list, int);
		}
		if ((format[index] == '*' || ft_isdigit(format[index]) ||
					format[index] == '-') && g_point == 1)
			get_precision(format, &index, arg_list);
		index++;
	}
	return (index);
}

int		ft_check_flags(const char *format, int index, va_list arg_list)
{
	g_justify = -1;
	g_point = 0;
	g_width = 0;
	g_precision = 0;
	g_found = 'a';
	if (format[index] == '-')
	{
		g_justify = 1;
		index++;
	}
	index = check_format(format, index, arg_list);
	if (!(ft_is_flag(format[index])))
		return (index - 1);
	if (g_width < 0)
	{
		g_width = -g_width;
		g_justify = 1;
	}
	if (g_precision < 0)
	{
		g_found = 'w';
		g_precision = 0;
	}
	ft_flags(format[index], arg_list);
	return (index);
}
