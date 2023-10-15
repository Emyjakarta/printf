#include "main.h"
/**
 * c_handler-handle characters
 * @ptr: name of the variable argument list
 * Return:void
 */
void c_handler(va_list ptr)
{
	char c = va_arg(ptr, int);

	write(1, &c, 1);
}
/**
 * s_handler-handle strings
 * @ptr: name of the variable argument list
 * Return:void
 */
void s_handler(va_list ptr)
{
	char *str = va_arg(ptr, char *);
	int length = len_str(str);

	write(1, str, length);
}
/**
 * b_handler-handle binary
 * @ptr: name of the variable argument list
 * Return:void
 */
void b_handler(va_list ptr)
{
	unsigned int num = va_arg(ptr, unsigned int);

	_convert_to_binary(num);
}
/**
 * d_handler-handle integers
 * @ptr: name of the variable argument list
 * Return:void
 */
void d_handler(va_list ptr)
{
	int num = va_arg(ptr, int);

	int_conversion(num);
}
Handle_Format *get_handle_format()
{
	static Handle_Format handle_format[] = {
		{'c', c_handler},
		{'s', s_handler},
		{'d', d_handler},
		{'b', b_handler},
		{'%', NULL},
		{'\0', NULL},
	};
	return (handle_format);
}
