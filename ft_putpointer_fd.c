/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:30:15 by acouture          #+#    #+#             */
/*   Updated: 2023/01/19 13:32:20 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	n_len(long long unsigned n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		ft_putstr_fd("0x0", 2);
	if (n < 0)
		i++;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static int	ft_pointer_to_hexa(long long unsigned nb)
{
	char			*str;
	char			*base;
	unsigned int	i;

	var.count = 0;
	if (nb == 0)
		ft_putnbr_fd(0, 1);
	base = "0123456789abcdef";
	str = malloc(sizeof(char) * n_len(nb) + 1);
	if (!str)
		return (1);
	str[n_len(nb)] = '\0';
	i = n_len(nb) - 1;
	while (nb > 0)
	{
		str[i] = base[nb % 16];
		nb = nb / 16;
		i--;
	}
	var.count += ft_putstr_fd("0x", 2);
	var.count += ft_putstr_fd(str, 1);
	free(str);
	return (var.count);
}

int ft_putpointer_fd(uintptr_t y)
{
	var.count += ft_pointer_to_hexa(y);
	return (var.count);
}