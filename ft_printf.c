/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:45:55 by iounejja          #+#    #+#             */
/*   Updated: 2019/11/27 13:46:02 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_printf(const char *format, ...)
{
    int i;
    int count;
    va_list arg_list;

    i = 0;
    count = 0;
    va_start(arg_list, format);
    while (format[i])
    {
        if (format[i] != '%')
        {
            write(1, &format[i], 1);
            count++;
        }
        if (format[i] == '%' && format[i + 1] == '%')
        {
            i++;
            write(1, &format[i], 1);
        }
        if (format[i] == '%' && format[i + 1] == 'c')
        {
            ft_putchar(va_arg(arg_list, int));
            i++;
        }
        if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
        {
            ft_putnbr(va_arg(arg_list, int));
            i++;
        }
        if (format[i] == '%' && format[i + 1] == 's')
        {
            ft_putstr(va_arg(arg_list, char *));
            i++;
        }
        if (format[i] == '%' && format[i + 1] == 'p')
        {
            ft_hex(va_arg(arg_list, unsigned long), 'p');
            i++;
        }
        if (format[i] == '%' && (format[i + 1] == 'x' || format[i + 1] == 'X'))
        {
            if (format[i + 1] == 'X')
                ft_hex(va_arg(arg_list, int), 'X');
            else
                ft_hex(va_arg(arg_list, int), 'x');
            i++;
        }
        i++;
    }
    va_end(arg_list);
    return (count);
}
