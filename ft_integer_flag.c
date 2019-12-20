/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:10:42 by iounejja          #+#    #+#             */
/*   Updated: 2019/12/20 18:53:11 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_zero_precision(char *nbr, int nb, char c)
{
	int ln;
	int s;
	int z;

	ln = (nb != 0) ? ft_strlen(nbr) : 0;
	s = (g_width > g_precision && g_precision > ln) ? g_width - g_precision : 0;
	if (g_precision <= ln || (g_width > 0 && g_precision == 0))
		s = g_width - ln;
	s = (c != 'u' && nb < 0 && g_precision && g_precision >= ln) ? s -= 1 : s;
	z = g_precision - ln;
	z = (nb < 0 && c != 'u') ? z += 1 : z;
	if (g_justify == 0 || g_justify == -1)
		ft_print(s, ' ');
	if (nb < 0 && c != 'u')
		ft_putchar('-');
	ft_print(z, '0');
	if (nb < 0 && c != 'u')
		ft_print_string(nbr, (ln--) - 1, 1);
	else if (nb != 0)
		ft_print_string(nbr, ln, 0);
	if (g_justify == 1)
		ft_print(s, ' ');
	s = (s < 0) ? 0 : s;
	z = (z < 0) ? 0 : z;
	g_count += (nb < 0 && c != 'u') ? ln + s + z + 1 : ln + s + z;
}

void	print_zero_width(char *nbr, int nb, char c)
{
	int l_nbr;

	l_nbr = (g_width > ft_strlen(nbr)) ? g_width - ft_strlen(nbr) : 0;
	if (nb < 0 && c != 'u')
		ft_putchar('-');
	ft_print(l_nbr, '0');
	if (nb < 0 && c != 'u')
		ft_print_string(nbr, ft_strlen(nbr) - 1, 1);
	else
		ft_print_string(nbr, ft_strlen(nbr), 0);
	g_count += l_nbr + ft_strlen(nbr);
}

int		print_space(char *nbr)
{
	int l_nbr;

	l_nbr = ft_strlen(nbr);
	if (g_justify == -1)
		ft_print_spaces(l_nbr, ' ');
	ft_print_string(nbr, l_nbr, 0);
	if (g_justify == 1)
		ft_print_spaces(l_nbr, ' ');
	return (l_nbr);
}

void	ft_integer_flag(char c, va_list arg_list)
{
	char	*nbr;
	int		nb;

	nb = (c == 'd' || c == 'i') ? va_arg(arg_list, int) :
	va_arg(arg_list, unsigned int);
	nbr = (c == 'd' || c == 'i') ? ft_itoa(nb) : ft_itoa_u(nb);
	if (g_found == 'a')
	{
		ft_putstr(nbr);
		g_count += ft_strlen(nbr);
	}
	else if (g_found == 'w')
	{
		if (g_justify == 0)
			print_zero_width(nbr, nb, c);
		if (g_justify == -1 || g_justify == 1)
			g_count += print_space(nbr);
	}
	else
		print_zero_precision(nbr, nb, c);
	free(nbr);
}
