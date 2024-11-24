/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:31:36 by go-donne          #+#    #+#             */
/*   Updated: 2024/11/24 10:41:04 by go-donne         ###   ########.fr       */
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


// MINI TEST SUITE //

#include <stdio.h>
#include <stdarg.h>

// Helper: handles test organisation & properly handles variadic arguments
static void test_printf(const char *test_name, const char *format, ...)
{
    va_list args1, args2;
    int ft_ret, std_ret;

    printf("\n=== %s ===\n", test_name);

    // Initialize first set of arguments
    va_start(args1, format);
    // Make a copy for the second printf
    va_copy(args2, args1);

    // Print test header
    printf("Format: \"%s\"\n", format);
    printf("Output:\n");

    // Run both printf versions
    printf("ft_printf  > ");
    ft_ret = vprintf(format, args1);
    printf("\nprintf     > ");
    std_ret = vprintf(format, args2);
    printf("\n");

    // Compare return values
    printf("Returns: ft=%d, std=%d %s\n",
           ft_ret, std_ret,
           (ft_ret == std_ret) ? "✓" : "✗");

    // Cleanup
    va_end(args1);
    va_end(args2);
}


/* // Simple test cases with simple return value comparison
int main(void)
{
    char *str = "Hello";
    void *ptr = &str;

    // Basic Tests
    test_printf("Simple String", "Basic text\n");
    test_printf("Character", "Char: %c\n", 'A');
    test_printf("String", "String: %s\n", str);
    test_printf("Pointer", "Pointer: %p\n", ptr);
    test_printf("Integer", "Number: %d\n", 42);
    test_printf("Unsigned", "Unsigned: %u\n", 4294967295U);
    test_printf("Hexadecimal", "Hex: %x %X\n", 255, 255);
    test_printf("Percent", "%%\n");

    // Edge Cases
    test_printf("NULL String", "Null str: %s\n", NULL);
    test_printf("NULL Pointer", "Null ptr: %p\n", NULL);
    test_printf("INT_MIN", "Min int: %d\n", INT_MIN);
    test_printf("INT_MAX", "Max int: %d\n", INT_MAX);

    // Mixed Tests
    test_printf("Multiple Types",
                "Mix: %c %s %p %d %i %u %x %X %%\n",
                'Z', "test", ptr, -42, 42, 42U, 42, 42);

    return (0);
} */


/*
// Basic printf tests: (separate from above test suite)
//
// Quick visual comparison:
// - between ft_printf and printf outputs
// - and that return values match

#include <stdio.h>
#include <limits.h>

int main(void)
{
    int ft_ret, std_ret;
    char c = 'A';
    char *str = "Hello World";
    int num = 42;
    void *ptr = &num;
    unsigned int uint = 4294967295;

    printf("\n=== Basic Functionality Tests ===\n");

    // Test 1: Basic string
    printf("\nTest 1 - Basic string:\n");
    ft_ret = ft_printf("This is a test\n");
    std_ret = printf("This is a test\n");
    printf("Returns: ft=%d, std=%d\n", ft_ret, std_ret);

    // Test 2: Character (%c)
    printf("\nTest 2 - Character:\n");
    ft_ret = ft_printf("Character: %c\n", c);
    std_ret = printf("Character: %c\n", c);
    printf("Returns: ft=%d, std=%d\n", ft_ret, std_ret);

    // Test 3: String (%s)
    printf("\nTest 3 - String:\n");
    ft_ret = ft_printf("String: %s\n", str);
    std_ret = printf("String: %s\n", str);
    printf("Returns: ft=%d, std=%d\n", ft_ret, std_ret);

    // Test 4: Pointer (%p)
    printf("\nTest 4 - Pointer:\n");
    ft_ret = ft_printf("Pointer: %p\n", ptr);
    std_ret = printf("Pointer: %p\n", ptr);
    printf("Returns: ft=%d, std=%d\n", ft_ret, std_ret);

    // Test 5: Integer (%d/%i)
    printf("\nTest 5 - Integer:\n");
    ft_ret = ft_printf("Integer (d): %d, (i): %i\n", num, num);
    std_ret = printf("Integer (d): %d, (i): %i\n", num, num);
    printf("Returns: ft=%d, std=%d\n", ft_ret, std_ret);

    // Test 6: Unsigned (%u)
    printf("\nTest 6 - Unsigned:\n");
    ft_ret = ft_printf("Unsigned: %u\n", uint);
    std_ret = printf("Unsigned: %u\n", uint);
    printf("Returns: ft=%d, std=%d\n", ft_ret, std_ret);

    // Test 7: Hexadecimal (%x/%X)
    printf("\nTest 7 - Hexadecimal:\n");
    ft_ret = ft_printf("Hex (lower): %x, (upper): %X\n", num, num);
    std_ret = printf("Hex (lower): %x, (upper): %X\n", num, num);
    printf("Returns: ft=%d, std=%d\n", ft_ret, std_ret);

    // Test 8: Percent sign (%%")
    printf("\nTest 8 - Percent sign:\n");
    ft_ret = ft_printf("Percent: %%\n");
    std_ret = printf("Percent: %%\n");
    printf("Returns: ft=%d, std=%d\n", ft_ret, std_ret);

    // Test 9: Edge Cases
    printf("\nTest 9 - Edge Cases:\n");
    ft_ret = ft_printf("NULL string: %s\n", NULL);
    std_ret = printf("NULL string: %s\n", NULL);
    printf("Returns: ft=%d, std=%d\n", ft_ret, std_ret);

    ft_ret = ft_printf("NULL pointer: %p\n", NULL);
    std_ret = printf("NULL pointer: %p\n", NULL);
    printf("Returns: ft=%d, std=%d\n", ft_ret, std_ret);

    ft_ret = ft_printf("INT_MIN: %d\n", INT_MIN);
    std_ret = printf("INT_MIN: %d\n", INT_MIN);
    printf("Returns: ft=%d, std=%d\n", ft_ret, std_ret);

    return (0);
}
 */
