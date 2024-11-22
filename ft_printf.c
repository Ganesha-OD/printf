/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:31:36 by go-donne          #+#    #+#             */
/*   Updated: 2024/11/22 13:16:39 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Validation Protocol
Process specifier & handle conversion
Routes format specifiers to their handlers */
static int	handle_format(char specifier, va_list args)
{
	if (specifier == 'c')
		return (handle_char(args));
	if (specifier == 's')
		return (handle_string(args));
	if (specifier == '%')
		return (handle_percent());
	if (specifier == 'p')
		return (handle_pointer(args));
	if (specifier == 'd' || specifier == 'i')
		return (handle_integer(args));
	if (specifier == 'u')
		return (handle_unsigned(args));
	if (specifier == 'x' || specifier == 'X')
		return (handle_hex(args, specifier == 'X'));
	return (-1);
}

/* Helper 2: Error handling wrapper around handle_format */
static int	handle_format_char(char format_char, va_list args,
			va_list backup, int *chars_written)
{
	int	temp_result;

	temp_result = handle_format(format_char, args);
	if (temp_result == -1)
	{
		va_end(args);
		va_end(backup);
		return (-1);
	}
	*chars_written += temp_result;
	return (0);
}

/* Helper 3: Handles writing regular (non-format) characters */
static int	write_regular_char(char c, va_list args,
						va_list backup, int *chars_written)
{
	if (write(1, &c, 1) == -1)
	{
		va_end(args);
		va_end(backup);
		return (-1);
	}
	(*chars_written)++;
	return (0);
}

/* Helper 4: Main string processing loop */
static int	process_format_string(const char *format, va_list args,
			va_list backup)
{
	int	chars_written;
	int	status;

	chars_written = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			status = handle_format_char(*format, args, backup, &chars_written);
			if (status == -1)
				return (-1);
		}
		else
		{
			status = write_regular_char(*format, args, backup, &chars_written);
			if (status == -1)
				return (-1);
		}
		format++;
	}
	return (chars_written);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg_cursor;
	va_list	arg_backup;
	int		result;

	if (!format)
		return (-1);
	va_start(arg_cursor, format);
	va_copy(arg_backup, arg_cursor);
	result = process_format_string(format, arg_cursor, arg_backup);
	va_end(arg_cursor);
	va_end(arg_backup);
	return (result);
}

/* Mini Test Suite

(1) Overall structure:
- Helper to print test results: print_test_result
- Test runner (main function): calls each test. Tests are organised by category





(2) Notes: next-level planning:


// For printf:
#include <stdio.h>



print_test_result

Required information:
Test name: describes what's being tested
Input
my ft_printf implementation output
expected standard printf actual output



Test Categories:
├── Basic Functionality
│   ├── Single conversions
│   ├── Simple strings
│   └── Basic return values
│
├── Conversion-Specific Tests
│   ├── Characters (%c)
│   ├── Strings (%s)
│   ├── Integers (%d, %i)
│   ├── Unsigned (%u)
│   ├── Hex (%x, %X)
│   ├── Pointers (%p)
│   └── Percent (%%)
│
├── Edge Cases
│   ├── NULL values
│   ├── INT_MIN/MAX
│   ├── Empty strings
│   └── Zero values
│
├── Mixed Tests
│   ├── Multiple conversions
│   ├── Mixed with regular text
│   └── Sequential identical conversions
│
└── Return Value Tests
    ├── Single conversion lengths
    ├── Multiple conversion lengths
    └── Error conditions


NB:
I'm not going to worry about having results compared or reporting results but will rely on manual comparison
*/
