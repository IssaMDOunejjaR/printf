# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/19 11:45:27 by iounejja          #+#    #+#              #
#    Updated: 2019/12/20 13:32:34 by iounejja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_putchar.c \
	   ft_putstr.c \
	   ft_putnbr.c \
	   ft_printf.c \
	   ft_check_flags.c \
	   ft_flags.c \
	   ft_get_digit.c \
	   ft_hex_flags.c \
	   ft_hex.c \
	   ft_integer_flag.c \
	   ft_is_flag.c \
	   ft_itoa_u.c \
	   ft_len_hex.c \
	   ft_print_char.c \
	   ft_print_string.c \
	   ft_print.c \
	   ft_printf_spaces.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_putnbr.c \
	   ft_string_flag.c \
	   ft_strlen.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_itoa.c 

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

%.o : %.c
	gcc -Wall -Wextra -Werror -c $< -o $@ -I ft_printf.h

clean:
	rm -f *.o

fclean:	clean
		rm -f $(NAME)

re: fclean all