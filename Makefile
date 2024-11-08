# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 18:36:38 by go-donne          #+#    #+#              #
#    Updated: 2024/11/08 09:31:00 by go-donne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

// Source files in different modules
SRCS = ft_printf.c \
		ft_printf_utils.c \
		ft_printf_convert_basic.c \
		ft_printf_convert_hex.c \
		ft_printf_convert_num.c

OBJS = $(SRCS:.c=.o)
HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
