/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_to_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:30:40 by acouture          #+#    #+#             */
/*   Updated: 2023/01/19 13:27:37 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	n_len(long long unsigned n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

char	*low_to_up(char c, char *s)
{
	int	i;

	i = 0;
	if (c == 'X')
	{
		while (s[i])
		{
			if (s[i] >= 'a' && s[i] <= 'f')
				s[i] -= 32;
			i++;
		}
	}
	return (s);
}



int	ft_itoa_to_hexa(long long unsigned nb, char c)
{
	char			*str;
	char			*base;
	unsigned int	i;
	int count; 

	count = 0;
	if (nb == 0)
		return (count += ft_putchar_fd('0', 1));
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
	count += ft_putstr_fd(low_to_up(c, str), 1);
	free(str);
	return (count);
}
