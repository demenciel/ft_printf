# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acouture <acouture@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 12:30:05 by acouture          #+#    #+#              #
#    Updated: 2023/01/20 15:50:01 by acouture         ###   ########.fr        #
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
		
DEF_COLOR = \033[0;39m
GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m

OBJS = $(SRC:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME) $(SRC)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

	
clean:
	rm -f $(OBJS)
	@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"


fclean: clean
	rm -f $(NAME)
	@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
	@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

.PHONY: all clean fclean re bonus
