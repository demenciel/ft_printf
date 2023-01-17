#ifndef LIBFT_PRINTF
#define LIBFT_PRINTF

#include "./libft/libft.h"
#include <stdarg.h>

typedef struct format_list
{
    char *temp;
    int i;
    int fd;
}               var_list;
var_list var;

int ft_printf(const char *format, ...);
void check_format_sp(char c, va_list args);
void ft_putnbr_unsigned_fd(unsigned int u, int fd);

#endif