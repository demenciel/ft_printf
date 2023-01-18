NAME = libftprintf.a

SRC =	ft_printf.c \
		ft_putnbr_unsigned_fd.c \
		ft_putpointer_fd.c \
		ft_itoa_to_hexa.c \
		
OBJS = $(SRC:%.c=%.o)

LIBFT = ft_printf/libft/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME) $(SRC)

$(NAME): $(OBJS)
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
