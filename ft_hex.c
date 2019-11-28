#include "ft_printf.h"

void    ft_hex(unsigned long p, char c)
{
    int i;
    unsigned long nb;
    char *str;

    i = 0;
    str = malloc(ft_strlen(ft_itoa((int)p)));
    while (p != 0)
    {
        nb = 0;
        nb = p % 16;
        if (nb < 10)
        {
            if (c == 'X')
                str[i] = ft_toupper(nb + 48);
            else
                str[i] = ft_tolower(nb + 48);
        }
        else
        {
            if (c == 'X')
                str[i] = ft_toupper(nb + 55);
            else
                str[i] = ft_tolower(nb + 55);
        }
        i++;
        p /= 16;
    }
    str[i] = '\0';
    if (c == 'p')
        ft_putstr("0x");
    while (i >= 0)
        write(1, &str[i--], 1);
}