#include "ft_printf.h"
#include <stdio.h>

int main()
{
    ft_printf("%d\n", -200000);
    ft_printf("%d\n", ft_printf("%d", -200000));

    printf("%d\n", -200000);
    printf("%d\n", printf("%d", -200000));
 
}