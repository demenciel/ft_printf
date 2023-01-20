#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{


    // x1 = &ptr2;

    ft_printf("%d\n", ft_printf(" %x ", LONG_MAX));

    printf("%d\n", printf(" %x ", LONG_MAX));
    
    ft_printf("\n");

    ft_printf("%d\n", ft_printf(" %x ", ULONG_MAX));

    printf("%d\n", printf(" %x ", ULONG_MAX));
 
}