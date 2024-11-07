/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:32:52 by go-donne          #+#    #+#             */
/*   Updated: 2024/11/07 19:38:28 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

/* Main printf function */
int		ft_printf(const char *format, ...);

/* Utility functions */
int		ft_write_char(char c);
int		ft_write_str(char *str);
size_t	ft_strlen(const char *s);

/* Conversion functions */
int		ft_convert_char(va_list args);
int		ft_convert_string(va_list args);
int		ft_convert_pointer(va_list args);
int		ft_convert_number(va_list args, char type);

#endif
