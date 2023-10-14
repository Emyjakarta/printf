#include "main.h"
/**
 * _convert_to_binary - Print an unsigned integer in a binary format.
 * @num: Unsigned integer.
 */

void _convert_to_binary(unsigned int num)
{
	int Q, l, r;
	char bin_str[32], temp;

	Q = 0;
	while (num > 0)
	{
		bin_str[Q++] = (num % 2) + '0';
		num /= 2;
	}
	l = 0, r = Q - 1;
	while (l < r)
	{
		temp = bin_str[l];
		bin_str[l] = bin_str[r];
		bin_str[r] = temp;
		l++;
		r++;
	}
	bin_str[Q] = '\0';
	write(1, bin_str, Q);
}
