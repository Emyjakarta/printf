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
	size_t length = 0, size_t Q = 0;
	char buffer[BUFFER_SIZE];
	int buffer_index = 0;

	if (format == NULL)
		return (-1);
	va_start(ptr, format);

	for (Q = 0; format[Q] != '\0'; Q++)
	{
		if (buffer_index == BUFFER_SIZE - 1)
		{
			write(1, buffer, buffer_index), length += buffer_index;
			buffer_index = 0;
		}
		if (format[Q] != '%')
		{
			buffer[buffer_index++] = format[Q];
			continue;
		}
		if (get_handle_format(&format[Q + 1], &length, ptr))
		{
			Q += 2;
			continue;
		}
		if (format[Q + 1] == '%')
		{
			buffer[buffer_index++] = '%';
			Q++;
			continue;
		}
		buffer[buffer_index++] = format[Q];
	}
	if (buffer_index > 0)
	{
		write(1, buffer, buffer_index), length += buffer_index;
	}
	va_end(ptr);
	return (length);
}
