/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:30:32 by acouture          #+#    #+#             */
/*   Updated: 2023/01/18 12:32:24 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;

	var.fd = STDOUT_FILENO;
	var.i = 0;
	va_start(args, format);
	var.temp = malloc(sizeof(char) * ft_strlen(format) + 1);
	ft_memmove(var.temp, (char *)format, ft_strlen(format) + 1);
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

void	check_format_sp(char c, va_list args)
{
	var.fd = STDOUT_FILENO;
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), var.fd);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), var.fd);
	// else if (c == 'p')
	//     ft_putpointer_fd(va_arg(args, void*), var.fd);
	else if (c == 'i' || c == 'd')
		ft_putnbr_fd((va_arg(args, int)), var.fd);
	else if (c == 'u')
		ft_putnbr_unsigned_fd((va_arg(args, unsigned int)), var.fd);
	else if (c == 'x')
		ft_itoa_to_hexa((va_arg(args, long long int)), c);
	else if (c == 'X')
		ft_itoa_to_hexa((va_arg(args, long long int)), c);
	else if (c == '%')
		ft_putchar_fd('%', var.fd);
}
