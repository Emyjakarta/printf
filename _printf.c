#include "main.h"
/**
 * _printf-function that produces output according to a format
 * Return: the number of characters printed (excluding
 * the null byte used to end output to strings)
 * write output to stdout, the standard output stream
 * @format: is a character string. The format string is composed of
 * zero or more directives. See man 3 printf for more detail.
 * You need to handle the following conversion specifiers: c, s, %
 * You don’t have to reproduce the buffer handling of
 * the C library printf function
 * You don’t have to handle the flag characters
 * You don’t have to handle field width
 * You don’t have to handle precision
 * You don’t have to handle the length modifiers
 */
int _printf(const char *format, ...)
{
	va_list ptr;
	int length = 0, locate;
	Handle_Format *handle_format = get_handle_format();

	va_start(ptr, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			length++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				length++;
			}
			else
			{
				locate = handle_format_specifier(format, handle_format, ptr);

				if (!locate)
				{
					write(1, format - 1, 2);
					length += 2;
				}
			}
		}
		format++;
	}
	va_end(ptr);
	return (length);
}
