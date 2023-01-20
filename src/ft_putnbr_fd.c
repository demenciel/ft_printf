/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:54:26 by acouture          #+#    #+#             */
/*   Updated: 2023/01/20 14:35:51 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	g_var.count = 0;
	g_var.top = 0;
	if (n == 0)
		return (g_var.count += write(1, "0", 1));
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", 1));
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
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
