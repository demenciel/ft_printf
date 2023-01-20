/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:55:15 by acouture          #+#    #+#             */
/*   Updated: 2023/01/20 15:53:56 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	g_var.count = 0;
	if (s == NULL)
		return (g_var.count = ft_putstr_fd("(null)", 1));
	while (*s)
	{
		g_var.count += ft_putchar_fd(*s, fd);
		s++;
	}
	return (g_var.count);
}
