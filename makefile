
NAME = libftprintf.a

SRC_PATH = ft_printf/libft_final/

SRC =	$(SRC_PATH)ft_atoi.c \
	 	$(SRC_PATH)ft_bzero.c \
		$(SRC_PATH)ft_calloc.c \
	 	$(SRC_PATH)ft_isalnum.c \
	 	$(SRC_PATH)ft_isalpha.c \
	 	$(SRC_PATH)ft_isascii.c \
	 	$(SRC_PATH)ft_isdigit.c \
	 	$(SRC_PATH)ft_isprint.c \
	 	$(SRC_PATH)ft_itoa.c \
	 	$(SRC_PATH)ft_memchr.c \
	 	$(SRC_PATH)ft_memcmp.c \
	 	$(SRC_PATH)ft_memcpy.c \
	 	$(SRC_PATH)ft_memmove.c \
	 	$(SRC_PATH)ft_memset.c \
	 	$(SRC_PATH)ft_putchar_fd.c \
	 	$(SRC_PATH)ft_putendl_fd.c \
	 	$(SRC_PATH)ft_putnbr_fd.c \
	 	$(SRC_PATH)ft_putstring_fd.c \
	 	$(SRC_PATH)ft_split.c \
	 	$(SRC_PATH)ft_strchr.c \
	 	$(SRC_PATH)ft_strdup.c \
	 	$(SRC_PATH)ft_striteri.c \
	 	$(SRC_PATH)ft_strjoin.c \
	 	$(SRC_PATH)ft_strlcat.c \
	 	$(SRC_PATH)ft_strlcpy.c \
	 	$(SRC_PATH)ft_strlen.c \
	 	$(SRC_PATH)ft_strmapi.c \
	 	$(SRC_PATH)ft_strncmp.c \
	 	$(SRC_PATH)ft_strnstr.c \
	 	$(SRC_PATH)ft_strrchr.c \
	 	$(SRC_PATH)ft_strtrim.c \
	 	$(SRC_PATH)ft_substr.c \
	 	$(SRC_PATH)ft_tolower.c \
	 	$(SRC_PATH)ft_toupper.c \

OBJS = $(SRC:%.c=%.o)

HEADER_PATH = ft_printf/libft_final/libft.h

HEADER = $(HEADER_PATH)libft.h

CC = gcc

FLAGS = -Wall -Werror -Wextra -I $(HEADER_PATH)

all: $(NAME)

$(NAME): printf
	ar -rc $(NAME) $(OBJS)
	make clean

printf: $(SRC)
	$(CC) $(FLAGS) -c $(SRC)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
