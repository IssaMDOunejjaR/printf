/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:33:58 by iounejja          #+#    #+#             */
/*   Updated: 2019/12/18 18:03:41 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_spaces(int l_str, char c)
{
	while (g_width - l_str > 0)
	{
		ft_putchar(c);
		g_width--;
		g_count += 1;
	}
}
