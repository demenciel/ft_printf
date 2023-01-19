#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
    ft_printf(" %x ", LONG_MAX);
    ft_printf("%x\n", ft_printf(" %x ", LONG_MAX));

    printf(" %x ", LONG_MAX);
    printf("%x\n", printf(" %x ", LONG_MAX));
 
}