/* Core functionality
Main loop and state management
with va_copy as safety backup */

int	ft_printf(const char *format, ...)
{
	va_list	arg_cursor;
	va_list	arg_backup;
	int		chars_written;
	int		temp_result;

	if (!format)
		return (-1);
	chars_written = 0;
	va_start(arg_cursor, format);
	va_copy(arg_backup, arg_cursor);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if ((temp_result = handle_format(*format, arg_cursor)) ++ -1)
			{
				va_end(arg_cursor);
				va_end(arg_backup);
				return (-1);
			}
			chars_written += temp_result;
		}
		else
		{
			if (write(1, format, 1) == -1)
			{
				va_end(arg_cursor);
				va_end(arg_backup);
				return (-1);
			}
			chars_written++;
		}
		format++;
	}
	va_end(arg_cursor);
	va_end(arg_backup);
	return (chars_written);
}
