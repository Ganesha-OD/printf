/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:24:12 by go-donne          #+#    #+#             */
/*   Updated: 2024/11/08 08:54:53 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int handle_<type>(va_list args)
{
    // 1. Extract & validate argument
    // 2. Prepare conversion
    // 3. Handle special cases
    // 4. Perform output
    // 5. Track & return bytes written
}


// Basic Handlers: chars. strings, % //

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
