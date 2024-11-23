/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert_hex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:06:07 by go-donne          #+#    #+#             */
/*   Updated: 2024/11/23 10:07:11 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* Hexadecimal Conversion Helpers
 * Convert numbers to hexadecimal representation
 * Used by %x, %X (integers) and %p (pointers) conversions
 */
/* get_hex_chars: creates string of hex digits for conversion
 * Provides either uppercase (0-9A-F) or lowercase (0-9a-f) hex digits
 * Used internally by write_hex_recursive_long
 *
 * @param uppercase   0 for lowercase, 1 for uppercase
 * @return           Pointer to static string of hex digits
 */
static const char	*get_hex_chars(int uppercase)
{
	if (uppercase)
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}

/* Recursively writes an unsigned long number in hexadecimal format
 * Handles both regular integers (%x, %X) and memory addresses (%p)
 * Writes digits from left to right through recursive descent
 *
 * @param value      Number to convert (handles full unsigned long range)
 * @param uppercase  0 for lowercase (0-9a-f), 1 for uppercase (0-9A-F)
 * @return          Number of characters written, or -1 on error
 */
static int	write_hex_recursive_long(unsigned long value, int uppercase)
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

/* Hexadecimal conversion handlers (integers and pointers) */
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
