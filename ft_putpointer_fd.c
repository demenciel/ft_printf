/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:30:15 by acouture          #+#    #+#             */
/*   Updated: 2023/01/20 14:19:59 by acouture         ###   ########.fr       */
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

	g_var.count = 0;
	if (nb == 0)
	{
		g_var.count += write(1, "0x0", 3);
		return (g_var.count);
	}
	g_var.base = "0123456789abcdef";
	str = malloc(sizeof(char) * n_len(nb) + 1);
	if (!str)
		return (0);
	str[n_len(nb)] = '\0';
	i = n_len(nb) - 1;
	while (nb > 0)
	{
		str[i--] = g_var.base[nb % 16];
		nb = nb / 16;
		g_var.count++;
	}
	g_var.count += ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	free(str);
	return (g_var.count + 2);
}

int	ft_putpointer_fd(uintptr_t y)
{
	return (ft_pointer_to_hexa(y));
}
