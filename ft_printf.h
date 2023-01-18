/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:30:27 by acouture          #+#    #+#             */
/*   Updated: 2023/01/18 14:29:54 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF
# define LIBFT_PRINTF

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct format_list
{
	char	*temp;
	int		i;
	int		fd;
}			var_list;
var_list	var;

int			ft_printf(const char *format, ...);
void		check_format_sp(char c, va_list args);

void		ft_putnbr_unsigned_fd(unsigned int u, int fd);
void		ft_itoa_to_hexa(long long unsigned nb, char c);
void		ft_putpointer_fd(uintptr_t y);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *str);

#endif