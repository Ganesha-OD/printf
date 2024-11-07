/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:37:56 by go-donne          #+#    #+#             */
/*   Updated: 2024/11/07 12:07:07 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// Possible helper: format specifier detection

static int	is_valid_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' ||
		c == 'd' || c == 'i' || c == 'u' ||
		c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	write_char(char c)
{
	int	write_result;

	write_result = write(1, &c, sizeof(c));
	if (write_result == -1)
		return (-1);
	return (1);
}

int	ft_printf*const char *format, ...)
{
	va_list	arg_cursor;
	int		chars_written;

	chars_written = 0;
	if (!format)
		return (-1);
	va_start(arg_cursor, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			// TODO: Handle format specifier
			// arg_cursor used here to get argument
		}
		else
		{
			if (write_char(*format) == -1)
			{
				va_end(arg_cursor);
				return (-1);
			}
			chars_written++;
		}
		format++;
	}
	va_end(arg_cursor);
	return (chars_written);
}
