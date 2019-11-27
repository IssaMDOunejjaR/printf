/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:46:12 by iounejja          #+#    #+#             */
/*   Updated: 2019/11/27 13:46:15 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     main()
{
    char a = 'a';
    char b = 'b';
    int c = 10;
    char *str = "issam";
    char *p = &a;
    
    //printf("ft_printf = %d\n", ft_printf("Hello World! + %p\n", p));
    printf("%d\n", (unsigned int)p);
    printf("%p\n", p);
    return (0);
}
