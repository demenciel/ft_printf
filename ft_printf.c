#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    var.fd = STDOUT_FILENO;
    var.i = 0;
    va_list args;
    va_start(args, format);

    var.temp = malloc(sizeof(char) * ft_strlen(format) + 1);
    ft_memmove(var.temp, (char*)format, ft_strlen(format) + 1);
    while (var.temp[var.i])
    {
        if (var.temp[var.i] == '%')
        {
            var.i++;
            check_format_sp(var.temp[var.i], args);
        }
        else 
            ft_putchar_fd(var.temp[var.i], var.fd);
        var.i++;
    }
    free(var.temp);
    return (ft_strlen(format));
}

void check_format_sp(char c, va_list args)
{ 
    var.fd = STDOUT_FILENO;
    if (c == 'c')
        ft_putchar_fd(va_arg(args, int), var.fd);
    else if (c == 's')
        ft_putstr_fd(va_arg(args, char*), var.fd);
/*     else if (c == 'p')
        // pointeur afficher as a hexa output
    else if (c == 'd')
        // pass va_arg as a decimal output */
    else if (c == 'i')
        ft_putnbr_fd((va_arg(args, int)), var.fd);
    else if (c == 'u')
        ft_putnbr_unsigned_fd((va_arg(args, unsigned int)), var.fd);    /*
    else if (c == 'x')
        // pass va_arg as a hexa number in minuscule output
    else if (c == 'X')
        // pass va_arg as a hexa number in capital output
    else if (c == '%')
        // pass va_arg as a percentage output */
}

