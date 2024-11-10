/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert_basic.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:24:12 by go-donne          #+#    #+#             */
/*   Updated: 2024/11/10 12:26:00 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		chars_written;
	int		result;

	str = va_arg(args, char *);
	chars_written = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		result = write(1, str, 1);
		if (result == -1)
			return (-1);
		chars_written++;
		str++;
	}
	return (chars_written);
}

int	handle_percent(void)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}
