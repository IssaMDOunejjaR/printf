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
    char c;
    int a;

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
        if (format[i + 1] == 'c')
        {
            c = va_arg(arg_list, int);
            write(1, &c, 1);
            i++;
        }
        /*if (format[i + 1] == 'd' || format[i + 1] == 'i')
        {
            a = va_arg(arg_list, int);
            write(1, &a, 1);
            i++;
        }*/
        i++;
    }
    va_end(arg_list);
    return (count);
}
