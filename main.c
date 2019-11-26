#include "ft_printf.h"

int     main()
{
    char a = 'a';

    printf("ft_printf = %d\n", ft_printf("Hello%cWorld!%c%c\n"));
    //printf("%-r\n", a);
    return (0);
}