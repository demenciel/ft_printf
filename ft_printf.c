/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:30:32 by acouture          #+#    #+#             */
/*   Updated: 2023/01/18 14:40:46 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;

	var.fd = STDOUT_FILENO;
	var.i = 0;
	va_start(args, format);

	if (*format == '\0')
		return(0);
	while (format[var.i])
	{
		if (format[var.i] == '%')
		{
			var.i++;
			check_format_sp(format[var.i], args);
		}
		else
			ft_putchar_fd(format[var.i], var.fd);
		var.i++;
	}
	return (var.i - 1);
}

void	check_format_sp(char c, va_list args)
{
	var.fd = STDOUT_FILENO;
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), var.fd);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), var.fd);
	else if (c == 'p')
		ft_putpointer_fd(va_arg(args, unsigned long));
	else if (c == 'i' || c == 'd')
		ft_putnbr_fd((va_arg(args, int)), var.fd);
	else if (c == 'u')
		ft_putnbr_unsigned_fd((va_arg(args, unsigned int)), var.fd);
	else if (c == 'x')
		ft_itoa_to_hexa((va_arg(args, long long unsigned int)), c);
	else if (c == 'X')
		ft_itoa_to_hexa((va_arg(args, long long unsigned int)), c);
	else if (c == '%')
		ft_putchar_fd('%', var.fd);
}
