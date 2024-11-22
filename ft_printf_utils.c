/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:46:06 by go-donne          #+#    #+#             */
/*   Updated: 2024/11/21 15:02:53 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Basic I/O Safety Protocol */
int	write_char_safely(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

/* Multi-character Safety Protocol */
int	write_string_safely(const char *str)
{
	int	len;

	if (!str)
		return (-1);
	len = 0;
	while (str[len])
		len++;
	if (write(1, str, len) == -1)
		return (-1);
	return (len);
}
