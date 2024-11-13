/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:07:52 by go-donne          #+#    #+#             */
/*   Updated: 2024/11/13 12:11:34 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

/* For va_list */
# include <stdarg.h>
// For write
# include <unistd.h>

/* Core I/O utilities */
int			write_char_safely(char c);
int			write_string_safely(const char *str);
size_t		ft_strlen(const char *s);

/* Conversion / format handling utilities */
int handle_char(va_list args);
int handle_string(va_list args);
int handle_percent(void);
int handle_pointer(va_list args);
int handle_integer(va_list args);
int handle_unsigned(va_list args);
int handle_hex(va_list args, int uppercase);

#endif
