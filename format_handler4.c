#include "main.h"
/**
 * u_handler - Handle unsigned integers.
 * @ptr: Variable argument list.
 * Return: Length of the printed unsigned integer.
 */
int u_handler(va_list ptr)
{
	unsigned int number = va_arg(ptr, unsigned int);
	char u_num_str[20];
	int length = u_num_to_str(number, u_num_str);
	int total_length = length;

	if (number != 0)
	{
		write(1, "+", 1);
		total_length++;
	}
	else
	{
		write(1, " ", 1);
		total_length++;
	}
	return (write(1, u_num_str, length) + total_length);
}
/**
 * o_handler - Handle octal integers.
 * @ptr: Variable argument list.
 * Return: Length of the printed octal integer
 */
int o_handler(va_list ptr)
{
	unsigned int number = va_arg(ptr, unsigned int);
	char num_str[20];
	int length = octal_to_str(number, num_str);

	write(1, "0", 1);
	return (write(1, num_str, length) + 1);
}
/**
 * x_handler - Handle lowercase hexadecimal integers
 * @ptr: Variable argument list
 * Return: Length of the printed lowercase hexadecimal integer
 */
int x_handler(va_list ptr)
{
	unsigned int number = va_arg(ptr, unsigned int);
	char num_str[20];
	int length = hex_to_str(number, num_str, 0);

	write(1, "0x", 2);
	return (write(1, num_str, length) + 2);
}
/**
 * X_handler - Handle uppercase hexadecimal integers
 * @ptr: Variable argument list
 * Return: Length of the printed uppercase hexadecimal integer
 */
int X_handler(va_list ptr)
{
	unsigned int number = va_arg(ptr, unsigned int);
	char num_str[20];
	int length = hex_to_str(number, num_str, 1);

	write(1, "0X", 2);
	return (write(1, num_str, length) + 2);
}
/**
 * S_handler-handle strings with special formatting for
 * non-printable characters
 * @ptr: variable argument list
 * Return:length of the formatted string
 */
int S_handler(va_list ptr)
{
	char *str = va_arg(ptr, char *);
	int length = 0;

	if (str == NULL)
		return (write(1, "", 0));
	while (*str)
	{
		if (*str >= 32 && *str < 127)
		{
			length += write(1, str, 1);
		}
		else
		{
			length += write(1, "\\x", 2);
			length += print_hex_value(*str);
		}
		str++;
	}
	return (length);
}
