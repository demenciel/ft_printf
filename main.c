#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
    int ptr = 0;
    void *x;

    x = &ptr;

    ft_printf(" %p ", x);
    ft_printf("%d\n", ft_printf(" %p ", x));

    printf(" %p ", x);
    printf("%d\n", printf(" %p ", x));
 
}