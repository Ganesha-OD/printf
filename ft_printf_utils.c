/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:46:06 by go-donne          #+#    #+#             */
/*   Updated: 2024/11/13 11:13:48 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

/* Basic I/O Safety Protocol */
int	write_char_safely(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

/* Multi-character Safety Protocol */
int	write_string_safely(const char *str)
{
	int	len;

	if (!str)
		return (-1);
	len = 0;
	while (str[len])
		len++;
	if (write(1, str, len) == -1)
		return (-1);
	return (len);
}

/* Validation Protocol
Process specifier & handle conversion */
static int	handle_format(char specifier, va_list args)
{
	if (specifier == 'c')
		return (handle_char(args));
	if (specifier == 's')
		return (handle_string(args));
	if (specifier == '%')
		return (handle_percent(args));
	if (specifier == 'p')
		return (handle_pointer(args));
	if (specifier == 'd' || specifier == 'i')
		return (handle_integer(args));
	if (specifier == 'u')
		return (handle_unsigned(args));
	if (specifier == 'x' || specifier == 'X')
		return (handle_hex(args, specifier == 'X'));
	if (specifier == '%')
		return (write(1, "%", 1));
	return (-1);
}
