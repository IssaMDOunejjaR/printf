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
    int c = 15987;
    char *str = "issam";
    int *p = &c;
    
    ft_printf("Hello %a World!\n");
    //printf("%d\n", (unsigned int)p);
    printf("Hello World!\n");
    return (0);
}
