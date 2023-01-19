/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:30:27 by acouture          #+#    #+#             */
/*   Updated: 2023/01/19 14:31:49 by acouture         ###   ########.fr       */
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
	int		count;
	int		stack[10];
	int		top;
}			var_list;
var_list	var;

int			ft_printf(const char *format, ...);
int			check_format_sp(char c, va_list args);

int			ft_putnbr_unsigned_fd(unsigned int u, int fd);
int			ft_itoa_to_hexa(uintptr_t nb, char c);
int			ft_putpointer_fd(uintptr_t y);
int			ft_putchar_fd(char c, int fd);
int			ft_putnbr_fd(int n, int fd);
int			ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *str);

#endif