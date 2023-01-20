/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:30:15 by acouture          #+#    #+#             */
/*   Updated: 2023/01/20 13:49:50 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	n_len(uintptr_t n)
{
	unsigned int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static int	ft_pointer_to_hexa(uintptr_t nb)
{
	char			*str;
	unsigned int	i;

	var.count = 0;
	if (nb == 0)
	{
		var.count += write(1, "0x0", 3);
		return (var.count);
	}
	var.base = "0123456789abcdef";
	str = malloc(sizeof(char) * n_len(nb) + 1);
	if (!str)
		return (0);
	str[n_len(nb)] = '\0';
	i = n_len(nb) - 1;
	while (nb > 0)
	{
		str[i--] = var.base[nb % 16];
		nb = nb / 16;
		var.count++;
	}
	var.count += ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	free(str);
	return (var.count + 2);
}

int	ft_putpointer_fd(uintptr_t y)
{
	return (ft_pointer_to_hexa(y));
}
