#include "main.h"
/**
 * handle_format_specifier-handle a particular format specifier
 * @format: the format specifier
 * @handle_format: Array of Handle_Format structures
 * @ptr: pointer to the variable argument list
 * Return:1 if handled, 0 if not handled
 */
int handle_format_specifier(const char *format, Handle_Format *handle_format, va_list ptr)
{
	int Q;

	for (Q = 0; handle_format[Q].specify != '\0'; Q++)
	{
		if (handle_format[Q].specify == *format)
		{
			if (handle_format[Q].handler != NULL)
				handle_format[Q].handler(ptr);
			return (1);
		}
	}
	return (0);
}
