#include "main.h"
/**
 * num_to_str-converts integer to string
 * @num: integer to be converted
 * @str: pointer to the string
 * Return:length of string
 */
int num_to_str(int num, char *str)
{
	int Q = 0, R, remnant;
	int _is_minus = 0;
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
	R = 0;
	while (Q / 2 > R)
	{
		temp = str[R];
		str[R] = str[Q - R - 1];
		str[Q - R - 1] = temp;
		R++;
	}
	str[Q] = '\0';
	return (strlen(str));
}
