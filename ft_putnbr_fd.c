/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:54:26 by acouture          #+#    #+#             */
/*   Updated: 2023/01/19 12:58:45 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	var.count = 0;
	var.top = 0;
	if (n == 0)
		return (var.count += write(1, "0", 1));
	else
	{
		if (n == -2147483648)
			return (ft_putstr_fd("-2147483648", 1));
		else
		{
			if (n < 0)
			{
				ft_putchar_fd('-', fd);
				n = -n;
				var.count++;
			}
			while (n > 0)
			{
				var.stack[var.top++] = n % 10;
				n /= 10;
			}
			while (var.top > 0)
				var.count += ft_putchar_fd(var.stack[--var.top] + '0', fd);
		}
	}
	return (var.count);
}
