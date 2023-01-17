#include "ft_printf.h"
#include <stdio.h>

int main()
{
    char            str[] = "hello";
    char            c = 'c';
    int             i = 75352;
    unsigned int    u = -120;

    printf("%i%s fucker\n", i, str);
    ft_printf("%i%s fucker\n", i, str);

    printf("hello world!\n");
    ft_printf("hello world!\n");

    printf("%u\n", u);
    ft_printf("%u\n", u);
    return (0);
}