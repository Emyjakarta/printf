#include "main.h"
/**
 * num_to_str - Converts integers to string and print on the buffer.
 * @num: Integer to be converted.
 * @str: string to be printed on the buffer.
 */
void num_to_str(int num, char *str)
{
	int Q = 0, R = 0;
	int _is_minus = 0;
	int remnant;
	char temp;

	if (num < 0)
	{
		_is_minus = 1;
		num = -num;
	}
	if (num == 0)
	{
		str[Q++] = '0';
	}
	else
	{
		while (num != 0)
		{
			remnant = num % 10;
			str[Q++] = remnant + '0';
			num = num / 10;
		}
	}
	if (_is_minus)
	{
		str[Q++] = '-';
	}
	while (Q / 2 > R)
	{
		temp = str[R];
		str[R] = str[Q - R - 1];
		str[Q - R - 1] = temp;
		R++;
	}
	str[Q] = '\0';
}
