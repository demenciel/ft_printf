/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:30:21 by acouture          #+#    #+#             */
/*   Updated: 2023/01/19 10:36:02 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned_fd(unsigned int u, int fd)
{
	fd = STDOUT_FILENO;

	if (u < 0)
		var.count += ft_putstr_fd("4294967176", 1);
	else
	{
		if (u > 9)
		{
			ft_putnbr_fd(u / 10, fd);
			u = u % 10;
		}
		var.count += ft_putchar_fd(u + '0', fd);
	}
	return (var.count);
}