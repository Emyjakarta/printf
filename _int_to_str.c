#include "main.h"
/**
 * num_to_str - Converts integer to string.
 * @num: Integer to be converted
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
/**
 * octal_to_str-convert an unsigned integer to octal representation
 * @num: Unsigned integer to convert
 * @str: Output string for octal representation
 * Return:Length of the octal string.
 */
int octal_to_str(unsigned int num, char *str)
{
	int length = 0, Q;
	char temp;

	do {
		str[length++] = num % 8 + '0';
		num /= 8;
	} while (num != 0);
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
 * @num: Unsigned integer to convert
 * @str: Output string for octal representation
 * @upper: parameter used to determine whether the hexadecimal
 * representation should be uppercase or lowercase
 * Return:1 if uppercase, 0 if lowercase
 */
int hex_to_str(unsigned long num, char *str, int upper)
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
		str[length++] = hex_digits[num % 16];
		num /= 16;
	} while (num != 0);
	for (Q = 0; length / 2 > Q; Q++)
	{
		temp = str[Q];
		str[Q] = str[length - Q - 1];
		str[length - Q - 1] = temp;
	}
	str[length] = '\0';
	return (length);
}
