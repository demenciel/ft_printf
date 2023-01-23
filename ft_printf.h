/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:10:15 by acouture          #+#    #+#             */
/*   Updated: 2023/01/20 16:28:11 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct format_list
{
	char			*temp;
	char			*base;
	int				count;
	int				stack[10];
	int				top;
}					t_var_list;

struct format_list	g_var;

int					ft_printf(const char *format, ...);
int					format_iter(int count, const char *format, va_list args);
int					check_format_sp(char c, va_list args);

int					ft_putnbr_unsigned_fd(unsigned int u, int fd);
int					ft_puthexa(unsigned int nb, char c);
int					ft_putpointer_fd(uintptr_t y);
int					ft_putchar_fd(char c, int fd);
int					ft_putnbr_fd(int n, int fd);
int					ft_putstr_fd(char *s, int fd);
size_t				ft_strlen(const char *str);

#endif