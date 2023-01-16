#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    var.i = 0;
    va_list args;
    va_start(args, format);

    var.temp = malloc(sizeof(char) * ft_strlen(format) + 1);
    ft_memmove(var.temp, (char*)format, ft_strlen(format) + 1);
    while (format[var.i])
    {
        if (format[var.i] == '%')
        {
            i++;
            check_format_sp(format[var.i]);
        }
        else
        {
            ft_putstr_fd(var.temp, STDOUT_FILENO);
            break;
        }
        i++;
    }
    return (ft_strlen(format));
}

void check_format_sp(char c, va_list args)
{
    if (c == 'c')
        ft_putchar_fd(va_arg(args, int));
    else if (c == 's')
        ft_putchar_fd(va_arg(args, *char));
    else if (c == 'p')
        // pointeur afficher as a hexa output
    else if (c == 'd')
        // pass va_arg as a decimal output
    else if (c == 'i')
        // pass va_arg as a integer output
    else if (c == 'u')
        // pass va_arg as a unsigned int output
    else if (c == 'x')
        // pass va_arg as a hexa number in minuscule output
    else if (c == 'X')
        // pass va_arg as a hexa number in capital output
    else if (c == '%')
        // pass va_arg as a percentage output
}

