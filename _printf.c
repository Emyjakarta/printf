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
	unsigned int length = 0, Q = 0;

	va_start(ptr, format);
	if (format == NULL)
		return (-1);
	while (format[Q])
	{
		for (; format[Q] != '%' && format[Q]; Q++)
		{
			write(1, &format[Q], 1);
			length++;
		}
		if (!format[Q])
		{
			return (length);
		}
		if (get_handle_format(&format[Q + 1], &length, ptr))
		{
			Q += 2;
			continue;
		}
		if (format[Q + 1] == '%')
		{
			write(1, format, 1);
			length++;
			Q += 2;
			continue;
		}
		length++;
		write(1, format, 1);
		Q++;
	}
	va_end(ptr);
	return (length);
}
