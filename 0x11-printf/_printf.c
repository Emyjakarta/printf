#include "main.h"
/**
 *
 *
 */
int _printf(const char *format, ...)
{
	va_list ptr;
	const char *Q = format;
	int length = 0;
	
	va_start(ptr, format);
	while (*Q != '\0')
	{
		length++;
	}
	Q = format;
	while (*Q != '\0')
	{
		write(1, Q, 1);
		Q++;
	}
	va_end(ptr);
	return (length);
}


 
