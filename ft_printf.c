/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:30:32 by acouture          #+#    #+#             */
/*   Updated: 2023/01/19 12:34:31 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	var.fd = STDOUT_FILENO;
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
			count += ft_putchar_fd(format[var.i], var.fd);
		}
		format++;
	}
	va_end(args);
	return (count);
}

int	check_format_sp(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
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
		count += ft_itoa_to_hexa((va_arg(args, long long unsigned int)), c);
	else if (c == 'X')
		count += ft_itoa_to_hexa((va_arg(args, long long unsigned int)), c);
	else if (c == '%')
	{
		char c;
		c = '%';
		write(1, &c, 1);
		count++; 
	}
		
	return (count);
}
