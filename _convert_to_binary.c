#include "main.h"
/**
 * b_handler - Print an unsigned integer in a binary format.
 * @ptr: variable of type struct.
 * Return:Length of ptr.
 */

int b_handler(va_list ptr)
{
	int bin_str[32];
	int Q, length = 0;
	unsigned int num;

	num = va_arg(ptr, unsigned int);
	Q = 0;
	while (num > 0)
	{
		bin_str[Q] = num % 2;
		num /= 2;
		Q++;
	}
	for (Q = Q - 1; Q >= 0; Q--)
	{
		putchar('0' + bin_str[Q]);
		length++;
	}
	return (length);
}
