/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:46:12 by iounejja          #+#    #+#             */
/*   Updated: 2019/12/20 18:25:31 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

//# define FORMAT "TEST TEST 0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\t%%%15%%.3%", 7,5, "ABC",15,0
//# define FORMAT "TEST TEST 0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\t%%%15%%.3% %---15d %00015x", 7,5, "ABC",15,0,20,0x99
//# define FORMAT "ultimate2 %*d %*s %*x %*X %*i %*u\n", 1, 5000, 1, "hey", 10, 54700, 1, 300, 10000, -55, 1, -60
//# define FORMAT "ultimate2 %*d %*s %*x %*X %*i\n", 1, 5000, 1, "hey", 10, 54700, 1, 300, 10000, -55
//# define FORMAT "[%i], [%s], [%c], [%d], [%u], [%x], [%X], [%p]\n", 55, "Hello", 'a', -9000, -100, 7999, 7999, 1337
# define FORMAT "[%%%.3%]\n"

int     main()
{
    int x,y,i,j,u;

    int w = 12345;
    u = 0;
    i = -5;
    j = -5;

    //ft_printf(FORMAT);
    printf("%d\n", ft_printf(FORMAT));
    printf("%d\n", printf(FORMAT));
    /*while (i < 10)
    {
        j = -5;
        while (j < 10)
        {
            printf("\n\n");
            printf("[%d]--[%d]\n", i, j);
            x = ft_printf(FORMAT);
            y = printf(FORMAT);
            if (x != y)
            {
                printf("FAIL");
                u = 1;
                break ;
            }
            j++;
        }
        if (u != 0)
            break ;
        i++;
    }*/
    return (0);
}