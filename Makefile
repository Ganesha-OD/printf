# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 18:36:38 by go-donne          #+#    #+#              #
#    Updated: 2024/11/23 10:41:01 by go-donne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h

# Source files grouped by functionality
SRCS = ft_printf.c \
		ft_printf_utils.c \
		ft_printf_convert_basic.c \
		ft_printf_convert_num.c \
		ft_printf_convert_hex.c

OBJS = $(SRCS:.c=.o)

# Main rules
all: $(NAME)

# Enhanced compilation with header dependencies
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# File verification
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
