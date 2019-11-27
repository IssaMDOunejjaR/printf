#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int     ft_printf(const char *format, ...);
void    ft_putchar(char c);
void    ft_putstr(char *str);
void    ft_putnbr(int nb);
void    ft_hex(unsigned int p);

#endif