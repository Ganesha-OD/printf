/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:57:30 by go-donne          #+#    #+#             */
/*   Updated: 2024/11/21 15:03:36 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*get_hex_chars(int uppercase)
{
	if (uppercase)
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}

int	write_hex_recursive_long(unsigned long value, int uppercase)
{
	int			write_result;
	int			chars_written;
	const char	*hex_chars;

	chars_written = 0;
	hex_chars = get_hex_chars(uppercase);
	if (value >= 16)
	{
		write_result = write_hex_recursive_long(value / 16, uppercase);
		if (write_result == -1)
			return (-1);
		chars_written += write_result;
	}
	write_result = write_char_safely(hex_chars[value % 16]);
	if (write_result == -1)
		return (-1);
	return (chars_written + write_result);
}
