/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:30:21 by acouture          #+#    #+#             */
/*   Updated: 2023/04/21 16:26:23 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Write a number contained in an unsigned int to a file descriptor
 * @param n	The number to be printed
 * @param fd The file descriptor to write the number to
 * @return The number of character written
*/
int	ft_putnbr_unsigned_fd(unsigned int u, int fd)
{
	g_var.count = 0;
	if (u < 0)
		return (ft_putstr_fd("4294967176", 1));
	else
	{
		if (u > 9)
		{
			ft_putnbr_unsigned_fd(u / 10, fd);
			u = u % 10;
		}
		g_var.count += ft_putchar_fd(u + '0', fd);
		if (g_var.count < 0)
			return (-1);
	}
	return (g_var.count);
}
