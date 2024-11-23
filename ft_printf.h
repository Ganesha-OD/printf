/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:32:52 by go-donne          #+#    #+#             */
/*   Updated: 2024/11/23 10:11:12 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* System includes */
// va_list, va_start, va_arg, va_end, va_copy
# include <stdarg.h>
// write
# include <unistd.h>
// INT_MIN
# include <limits.h>

/* Core printf function */
int	ft_printf(const char *format, ...);

/* Core I/O utilities
These handle basic write operations with error checking */
int	write_char_safely(char c);
int	write_string_safely(const char *str);

/* Format specifier handlers
Each handles a specific conversion: %c, %s, %p, %d, %i, %u, %x, %X, %% */
// "Basic Handlers": characters, strings, % //
int	handle_char(va_list args);
int	handle_string(va_list args);
int	handle_percent(void);

// Hexadecimal conversion handlers (integers and pointers) //
int	handle_hex(va_list args, int uppercase);
int	handle_pointer(va_list args);

// Numeric handlers
int	handle_integer(va_list args);
int	handle_unsigned(va_list args);

#endif
