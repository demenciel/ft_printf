/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:30:32 by acouture          #+#    #+#             */
/*   Updated: 2023/04/21 16:23:29 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Perform a formatted print operation
 * 
 * This function is a custom implementation of the printf function.
 * It takes a format string and a variable number of arguments, then
 * prints the formatted output to stdout.
 *
 * @param format The format string containing placeholders for the arguments
 * @param ...    Variable number of arguments to be used with the format string
 * @return       The number of characters printed, excluding the null-byte
 */
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	if (*format == '\0')
		return (0);
	count += format_iter(count, format, args);
	va_end(args);
	return (count);
}

/**
 * @brief Iterates through the ft_printf arguments
 *
 *	Using the va_args, this functions iterates over the inputs of the ft_printf
 *	function. If i == '%', another function is called to check the format
 *	specifier following.
 * @param count The count of printed characters
 * @param format The format string containing placeholders for the arguments
 * @param args Object type containing information for the macros
 * @return The count of printed characters
*/
int	format_iter(int count, const char *format, va_list args)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += check_format_sp(*format, args);
			if (count == -1)
				return (-1);
		}
		else
		{
			count += ft_putchar_fd(*format, 1);
			if (count == -1)
				return (-1);
		}
		format++;
	}
	return (count);
}

/**
 * @brief Check of the format specifier
 *	The function compares the parameter (c) to some format specifiers.
 * @param c The character to comapare to the format specifier
 * @param args Object type containing information for the macros
 * @return The count of printed characters
*/
int	check_format_sp(char c, va_list args)
{
	int	count;

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
	else
		return (-1);
	return (count);
}
