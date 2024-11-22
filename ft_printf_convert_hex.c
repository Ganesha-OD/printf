/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert_hex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:06:07 by go-donne          #+#    #+#             */
/*   Updated: 2024/11/21 15:08:48 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Hexadecimal conversion handlers (integers and pointers) */
#include "ft_printf.h"

int	handle_hex(va_list args, int uppercase)
{
	unsigned int	number;

	number = va_arg(args, unsigned int);
	return (write_hex_recursive_long(number, uppercase));
}

int	handle_pointer(va_list args)
{
	void			*ptr;
	unsigned long	address;
	int				prefix_len;
	int				hex_len;

	ptr = va_arg(args, void *);
	if (!ptr)
		return (write_string_safely("0x0"));
	prefix_len = write_string_safely("0x");
	if (prefix_len == -1)
		return (-1);
	address = (unsigned long)ptr;
	hex_len = write_hex_recursive_long(address, 0);
	if (hex_len == -1)
		return (-1);
	return (prefix_len + hex_len);
}
