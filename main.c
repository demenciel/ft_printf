#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
    ft_printf(" %c %c %c ", '2', '1', 0);
    ft_printf("%d\n", ft_printf(" %c %c %c ", '2', '1', 0));

    printf(" %c %c %c ", '2', '1', 0);
    printf("%d\n", printf(" %c %c %c ", '2', '1', 0));
 
}