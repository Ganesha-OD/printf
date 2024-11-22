/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert_num.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:30:45 by go-donne          #+#    #+#             */
/*   Updated: 2024/11/21 15:40:12 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_negative(int *number)
{
	int	write_result;

	write_result = write_char_safely('-');
	if (write_result == -1)
		return (-1);
	*number = -(*number);
	return (write_result);
}

static int	write_number_recursive(int n)
{
	int		write_result;
	int		chars_written;
	char	digit;

	chars_written = 0;
	if (n >= 10)
	{
		write_result = write_number_recursive(n / 10);
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

int	handle_integer(va_list args)
{
	int	number;
	int	chars_written;
	int	write_result;

	number = va_arg(args, int);
	chars_written = 0;
	if (number == INT_MIN)
		return (write_string_safely("-2147483648"));
	if (number < 0)
	{
		write_result = handle_negative(&number);
		if (write_result == -1)
			return (-1);
		chars_written += write_result;
	}
	write_result = write_number_recursive(number);
	if (write_result == -1)
		return (-1);
	return (chars_written + write_result);
}
