#include "main.h"
/**
 * c_handler-handle characters
 * @ptr: name of the variable argument list
 * Return:1
 */
int c_handler(va_list ptr)
{
	char c = va_arg(ptr, int);

	return (write(1, &c, 1));
}
/**
 * s_handler-handle strings
 * @ptr: name of the variable argument list
 * Return:length of string
 */
int s_handler(va_list ptr)
{
	char *str = va_arg(ptr, char *);

	return (write(1, str, strlen(str)));
}
/**
 * percent_handler-handle %
 * @ptr: name of the variable argument list
 * Return:length
 */
int percent_handler(va_list ptr)
{
	(void)ptr;
	return (write(1, "%", 1));
}
/**
 * d_handler-handle integers
 * @ptr: name of the variable argument list
 * Return:void
 */
int d_handler(va_list ptr)
{
	int num = va_arg(ptr, int);

	return (int_conversion(num));
}
/**
 * get_handle_format-checks the conversion specifiers
 * @format: string of a particular format
 * @length: records the length of the characters printed
 * @ptr: the argument to be printed by _printf
 * Return:length
 */
int get_handle_format(const char *format, unsigned int *length, va_list ptr)
{
	unsigned int Q;
	Handle_Format handle_format[] = {
		{"c", c_handler},
		{"s", s_handler},
		{"%", percent_handler},
		{"d", d_handler},
		{"i", d_handler},
		{"b", b_handler},
		{NULL, NULL}
	};
	for (Q = 0; handle_format[Q].specify != NULL; Q++)
	{
		if (*format == *(handle_format[Q].specify))
		{
			*length += handle_format[Q].handler(ptr);
			return (1);
		}
	}
	return (0);
}
