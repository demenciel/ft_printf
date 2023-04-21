/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:30:40 by acouture          #+#    #+#             */
/*   Updated: 2023/04/21 16:24:05 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Calculates the length of a given number
 * @param n The number to check
 * @return The length of n
*/
static unsigned int	n_len(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

/**
 * @brief Turns a lowercase string to uppercase depending on the input checker
 * @param c The character to check if the function is executed
 * @param s The string to be turned into uppercases
 * @return The string either uppercased or lowercased
*/
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

/**
 * @brief Write a base 10 number in base 16
 * @param nb The number to be converted
 * @return The number of characters printed
*/
int	ft_puthexa(unsigned int nb)
{
	char			*str;
	char			*base;
	unsigned int	i;
	int				count;

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
		str[i--] = base[nb % 16];
		nb = nb / 16;
	}
	count += ft_putstr_fd(low_to_up(c, str), 1);
	free(str);
	return (count);
}
