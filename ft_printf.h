#ifndef LIBFT_PRINTF
#define LIBFT_PRINTF

#include "./libft/libft.h"
#include <stdarg.h>

typedef struct format_list
{
    char *temp;
    int i;
}               var_list;
var_list var;

int ft_printf(const char *format, ...);

#endif