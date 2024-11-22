/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert_uint.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:08:40 by go-donne          #+#    #+#             */
/*   Updated: 2024/11/21 15:08:48 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_uint_recursive(unsigned int n)
{
	int		write_result;
	int		chars_written;
	char	digit;

	chars_written = 0;
	if (n >= 10)
	{
		write_result = write_uint_recursive(n / 10);
		if (write_result == -1)
			return (-1);
		chars_written += write_result;
	}
	digit = (n % 10) + '0';
	write_result = write_char_safely(digit);
	if (write_result == -1)
		return (-1);
	return (chars_written + write_result);
}

int	handle_unsigned(va_list args)
{
	unsigned int	number;

	number = va_arg(args, unsigned int);
	return (write_uint_recursive(number));
}
