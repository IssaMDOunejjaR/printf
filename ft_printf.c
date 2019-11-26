#include "ft_printf.h"

int     ft_printf(const char *format, ...)
{
    int i;
    int count;
    int check;

    i = 0;
    count = 0;
    check = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
            {
                check++;
                i++;
            }
        }
        if (format[i] != '\0' && format[i] != '%')
        {
            write(1, &format[i++], 1);
            count++;
        }
    }
    return (check);
}