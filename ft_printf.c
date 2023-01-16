#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    int i;
    char *temp;

    i = 0;
    temp = malloc(sizeof(char) * ft_strlen(format));
    ft_strlcpy(temp, format, ft_strlen(format));
    ft_putstr_fd(temp, STDOUT_FILENO);
    return (ft_strlen(format));
}
