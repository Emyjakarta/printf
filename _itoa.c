#include "main.h"
/**
 * _itoa - Converts an integers to a string.
 * @num: Integers to be converted
 * @str: Buffer to store the resulting string
 * @base: Base for the numerical conversion
 * Return: Length of the resulting string
 */
int _itoa(int number, char *str, int base)
{
	int length = 0, isminus, remnant, begin, stop;
	char temp;

	if (number == 0)
	{
		str[length++] = '0';
		str[length] = '\0';
		return (1);
	}
	isminus = 0;
	if (number < 0 && base == 10)
	{
		isminus = 1;
		number = -number;
	}
	while (number != 0)
	{
		remnant = number % base;
		str[length++] = (remnant > 9) ? (remnant - 10) + 'a' : remnant + '0';
		number = number / base;
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
