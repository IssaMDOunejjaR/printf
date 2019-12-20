/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:02:14 by iounejja          #+#    #+#             */
/*   Updated: 2019/12/18 17:13:46 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*covert(char *str, char c, unsigned long p, int *index)
{
	unsigned long nb;

	while (p != 0)
	{
		nb = 0;
		nb = p % 16;
		if (nb < 10)
		{
			if (c == 'X')
				str[*index] = ft_toupper(nb + 48);
			else
				str[*index] = ft_tolower(nb + 48);
		}
		else
		{
			if (c == 'X')
				str[*index] = ft_toupper(nb + 55);
			else
				str[*index] = ft_tolower(nb + 55);
		}
		*index += 1;
		p /= 16;
	}
	return (str);
}

void	ft_hex(unsigned long p, char c)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * ft_len_hex(p));
	if (c == 'p' && p == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (p == 0)
	{
		ft_putchar('0');
		return ;
	}
	str = covert(str, c, p, &i);
	str[i--] = '\0';
	while (i >= 0)
		write(1, &str[i--], 1);
	free(str);
}
