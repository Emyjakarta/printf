#include "main.h"
/**
 * u_num_to_str - Converts an unsigned integer to string.
 * @num: unsigned integer to be converted
 * @str: pointer to the string
 * Return:length of string
 */
unsigned int u_num_to_str(unsigned int num, char *str)
{
	unsigned int Q = 0, R, remnant;
	char temp;

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
/**
 * print_hex_value-write the ASCII code value in hexadecimal
 * @value: ASCII value of the non-printable character
 * Return:length of the hexadecimal value (2 characters)
 */
int print_hex_value(char value)
{
	char hex_char[] = "0123456789ABCDEF";
	char hex_value[2];

	hex_value[0] = hex_char[(value >> 4) & 0xF];
	hex_value[1] = hex_char[value & 0xF];
	return (write(1, hex_value, 2));
}
