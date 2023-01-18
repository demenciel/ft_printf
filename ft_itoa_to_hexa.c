#include "ft_printf.h"
#include "stdio.h"

static int n_len(long unsigned int n)
{
    int i;

    i = 0;
    if (n < 0)
    {
        n = -n;
        i++;
    }
    while (n > 0)
    {
        n = n / 10;
        i++;
    }
    return (i);
}

char *low_to_up(char c, char *s)
{
    int i = 0;
    if (c == 'X')
    {
        while (s[i])
        {
            if (s[i] >= 'a' && s[i] <= 'f')
                s[i] -= 32;
            i++;
        }
    }
    return (s);
}

void ft_itoa_to_hexa(long unsigned int nb, char c)
{
    char *str;
    char *base = "0123456789abcdef";
    int i;

    str = malloc(sizeof(char) * n_len(nb) + 1);
    if (nb < 0)
    {
        ft_putchar_fd('-', 1);
        nb = nb * -1;
    }
    str[n_len(nb)] = '\0';
    i = n_len(nb) - 1;
    while (nb > 0)
    {
        str[i] = base[nb % 16];
        nb = nb / 16;
        i--;
    }
    ft_putstr_fd(low_to_up(c, str), 1);
    free(str);
}
