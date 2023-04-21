/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:53:15 by acouture          #+#    #+#             */
/*   Updated: 2023/04/21 16:23:42 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Write a single character to a file descriptor
 * 
 * 	This function is a custom implementation of the putchar function.
 * 	It takes a character and a file descriptor, then writes the character
 * 	to the specified file descriptor.
 *
 * @param c  The character to be written
 * @param fd The file descriptor to write the character to
 * @return The number of characters written (1 if successful,
		-1 if an error occurred)
*/
int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
