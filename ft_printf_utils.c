/* Basic utilities */
/* Basic output and string handling */

// Process specifier & handle conversion
static int	handle_format(char specifier, va_list args)
{
	if (specifier == 'c')
		return (handle_char(args));
	if (specifier == 's')
		return (handle_string(args));
	if (specifier == 'p')
		return (handle_pointer(args));
	if (specifier == 'd' || specifier == 'i')
		return (handle_integer(args));
	if (specifier == 'u')
		return (handle_unsigned(args));
	if (specifier == 'x' || specifier == 'X')
		return (handle_hex(args, specifier == 'X'));
	if (specifier == '%')
		return (write(1, "%", 1));
	return (-1);
}
