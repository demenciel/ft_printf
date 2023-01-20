/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:30:32 by acouture          #+#    #+#             */
/*   Updated: 2023/01/20 15:57:50 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	if (*format == '\0')
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += check_format_sp(*format, args);
		}
		else
		{
			count += ft_putchar_fd(format[g_var.i], 1);
		}
		format++;
	}
	va_end(args);
	return (count);
}

int	check_format_sp(char c, va_list args)
{
	int		count;

	count = 0;
	if (c == '%')
		count += ft_putchar_fd('%', 1);
	else if (c == 'c')
		count += ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		count += ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		count += ft_putpointer_fd(va_arg(args, unsigned long));
	else if (c == 'i' || c == 'd')
		count += ft_putnbr_fd((va_arg(args, int)), 1);
	else if (c == 'u')
		count += ft_putnbr_unsigned_fd((va_arg(args, unsigned int)), 1);
	else if (c == 'x')
		count += ft_puthexa((va_arg(args, long long unsigned int)), c);
	else if (c == 'X')
		count += ft_puthexa((va_arg(args, long long unsigned int)), c);
	return (count);
}
