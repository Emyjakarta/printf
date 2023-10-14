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
	int length = 0, string_length, num;
	unsigned int number;

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
			if (*format == '%' || *format == 'c')
			{
				write(1, format, 1), length++;
			}
			else if (*format == 's')
			{
				char *string = va_arg(ptr, char *);

				string_length = len_str(string), write(1, string, string_length);
				length += string_length;
			}
			else if (*format == 'd' || *format == 'i')
			{
				num = va_arg(ptr, int);
				int_conversion(num);

			}
			else if (*format == 'b')
			{
				number = va_arg(ptr, unsigned int);
				_convert_to_binary(number);
			}
		}
		format++;
	}
	va_end(ptr);
	return (length);
}
