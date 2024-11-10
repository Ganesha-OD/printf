/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert_pointer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:23:02 by go-donne          #+#    #+#             */
/*   Updated: 2024/11/10 12:34:40 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	write_char_safely(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

static const char	*get_hex_chars(void)
{
	return ("0123456789abcdef");
}

static int	write_address_hex(unsigned long value)
{
	int			write_result;
	int			chars_written;
	const char	*hex_chars;

	chars_written = 0;
	hex_chars = get_hex_chars();
	if (value >= 16)
	{
		write_result = write_hex_recursive(value / 16, uppercase);
		if (write_result == -1)
			return (-1);
		chars_written += write_result;
	}
	write_result = write_char_safely(hex_chars[value % 16]);
	if (write_result == -1)
		return (-1);
	return (chars_written + write_result);
}

int	handle_hex(va_list args, int uppercase)
{
	unsigned int	number;

	number = va_arg(args, unsigned int);
	return (write_hex_recursive(number, uppercase));
}
