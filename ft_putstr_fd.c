/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:55:15 by acouture          #+#    #+#             */
/*   Updated: 2023/01/19 11:29:41 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	var.count = 0;
	if (s == NULL)
		return (var.count = ft_putstr_fd("(null)", 1));
	while (*s)
	{
		var.count += ft_putchar_fd(*s, fd);
		s++;
	}
	return (var.count);
}
