#include "main.h"
/**
 * _itoa-convert an integer to a string
 * @num: integer to be converted
 * @str: Buffer to store the resulting string
 * @base: base for the numerical conversion
 * Return:Length of the resulting string
 */
int _itoa(int num, char *str, int base)
{
	int length = 0, isminus, remnant, begin, stop;
	char temp;

	if (num == 0)
	{
		str[length++] = '0';
		str[length] = '\0';
		return (1);
	}
	isminus = 0;
	if (num < 0 && base == 10)
	{
		isminus = 1;
		num = -num;
	}
	while (num != 0)
	{
		remnant = num % base;
		str[length++] = (remnant > 9) ? (remnant - 10) + 'a' : remnant + '0';
		num = num / base;
	}
	if (isminus)
		str[length++] = '-';
	begin = 0;
	stop = length - 1;
	while (begin < stop)
	{
		temp = str[begin];
		str[begin] = str[stop];
		str[stop] = temp;
		begin++;
		stop--;
	}
	str[length] = '\0';
	return (length);
}
