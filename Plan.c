/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:37:56 by go-donne          #+#    #+#             */
/*   Updated: 2024/11/07 12:21:35 by go-donne         ###   ########.fr       */
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


// Notes

Maybe use va_copy for memory safety & security
e.g. if process_arg_cursor fails partway, original arg_cursor still valid, original va_list not corrupted

State management
State tracking needed
e.g.:
typedef struct s_format_state
{
	// core tracking
	// current format specifier state
	// security state
}

Will increment some TDD before moving on
Can test:
- basic char output
- single format specifiers
- number conversions




# Key Questions to Consider

**Error Handling**

- How to handle partial writes?
- What about system call failures?
- Memory allocation failures?

**Buffer Management**

- Direct writing vs buffering?
- Maximum output limits?
- Performance trade-offs?

**Security Considerations**

- Format string vulnerabilities?
- Buffer overflow prevention?
- Resource exhaustion attacks?
