/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert_basic.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:24:12 by go-donne          #+#    #+#             */
/*   Updated: 2024/11/21 15:40:13 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// "Basic Handlers": characters, strings, % //

int	handle_char(va_list args)
{
	char	c;
	int		result;

	c = va_arg(args, int);
	result = write(1, &c, 1);
	if (result == -1)
		return (-1);
	return (1);
}

int	handle_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		return (write_string_safely("(null)"));
	return (write_string_safely(str));
}

int	handle_percent(void)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}
