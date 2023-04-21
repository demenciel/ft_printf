/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:54:26 by acouture          #+#    #+#             */
/*   Updated: 2023/04/21 16:26:14 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Write a number contained in an int to a file descriptor
 * @param n	The number to be printed
 * @param fd The file descriptor to write the number to
 * @return The number of character written
*/
int	ft_putnbr_fd(int n, int fd)
{
	g_var.count = 0;
	g_var.top = 0;
	if (n == 0)
		return (g_var.count += write(fd, "0", 1));
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", 1));
	else
	{
		if (n < 0)
		{
			if (ft_putchar_fd('-', fd) < 0)
				return (-1);
			n = -n;
			g_var.count++;
		}
		while (n > 0)
		{
			g_var.stack[g_var.top++] = n % 10;
			n /= 10;
		}
		while (g_var.top > 0)
			g_var.count += ft_putchar_fd(g_var.stack[--g_var.top] + '0', fd);
	}
	return (g_var.count);
}
