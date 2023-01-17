#include "ft_printf.h"
#include <stdio.h>

int main()
{
    char str[] = "hello";
    char c = 'c';

    printf("%s world!\n", str);
    ft_printf("%s%c muther %s fucker", str, c, str);
    return (0);
}