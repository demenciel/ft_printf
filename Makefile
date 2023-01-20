# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acouture <acouture@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 12:30:05 by acouture          #+#    #+#              #
#    Updated: 2023/01/20 14:35:02 by acouture         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		libftprintf.a

SRC_PATH = 	src/

SRC =		$(SRC_PATH)ft_printf.c \
			$(SRC_PATH)ft_putnbr_unsigned_fd.c \
			$(SRC_PATH)ft_putpointer_fd.c \
			$(SRC_PATH)ft_puthexa.c \
			$(SRC_PATH)ft_putpointer_fd.c \
			$(SRC_PATH)ft_putchar_fd.c \
			$(SRC_PATH)ft_putnbr_fd.c \
			$(SRC_PATH)ft_putstr_fd.c \
			$(SRC_PATH)ft_strlen.c \
		
OBJS = $(SRC:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME) $(SRC)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
