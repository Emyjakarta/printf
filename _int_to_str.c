#include "main.h"
/**
 * num_to_str - Converts integer to string.
 * @number: Integer to be converted
 * @str: pointer to the string
 * Return:length of string
 */
int num_to_str(int number, char *str)
{
	int Q = 0, R, remnant;
	int _is_minus = 0;
	char temp;

	if (number < 0)
	{
		_is_minus = 1;
		number = -number;
	}
	if (number == 0)
	{
		str[Q++] = '0';
	}
	else
	{
		while (number != 0)
		{
			remnant = number % 10;

			str[Q++] = remnant + '0';
			number = number / 10;
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
/**
 * octal_to_str-convert an unsigned integer to octal representation
 * @number: Unsigned integer to convert
 * @str: Output string for octal representation
 * Return:Length of the octal string.
 */
int octal_to_str(unsigned int number, char *str)
{
	int length = 0, Q;
	char temp;

	do {
		str[length++] = number % 8 + '0';
		number /= 8;
	} while (number != 0);
	for (Q = 0; length / 2 > Q; Q++)
	{
		temp = str[Q];
		str[Q] = str[length - Q - 1];
		str[length - Q - 1] = temp;
	}
	str[length] = '\0';
	return (length);
}
/**
 * hex_to_str-convert an unsigned integer to hexadecimal representation
 * @number: Unsigned integer to convert
 * @str: Output string for octal representation
 * @upper: parameter used to determine whether the hexadecimal
 * representation should be uppercase or lowercase
 * Return:1 if uppercase, 0 if lowercase
 */
int hex_to_str(unsigned int number, char *str, int upper)
{
	int length = 0, Q;
	char temp;
	char hex_digits[17];

	if (upper)
	{
		strcpy(hex_digits, "0123456789ABCDEF");
	}
	else
	{
		strcpy(hex_digits, "0123456789abcdef");
	}
	do {
		str[length++] = hex_digits[number % 16];
		number /= 16;
	} while (number != 0);
	for (Q = 0; length / 2 > Q; Q++)
	{
		temp = str[Q];
		str[Q] = str[length - Q - 1];
		str[length - Q - 1] = temp;
	}
	str[length] = '\0';
	return (length);
}
