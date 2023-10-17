#include "main.h"
/**
 * u_handler - Handle unsigned integers.
 * @ptr: Variable argument list.
 * Return: Length of the printed unsigned integer.
 */
int u_handler(va_list ptr)
{
	unsigned int num = va_arg(ptr, unsigned int);
	char u_num_str[20];
	int length;

	if (num == 0)
	{
		u_num_str[0] = '0';
		u_num_str[1] = '\0';
		return (write(1, u_num_str, 1));
	}
	length = u_num_to_str(num, u_num_str);

	return (write(1, u_num_str, length));
}
/**
 * o_handler - Handle octal integers.
 * @ptr: Variable argument list.
 * Return: Length of the printed octal integer
 */
int o_handler(va_list ptr)
{
	unsigned int num = va_arg(ptr, unsigned int);
	char num_str[20];

	octal_to_str(num, num_str);
	return (write(1, num_str, strlen(num_str)));
}
/**
 * x_handler - Handle lowercase hexadecimal integers
 * @ptr: Variable argument list
 * Return: Length of the printed lowercase hexadecimal integer
 */
int x_handler(va_list ptr)
{
	unsigned int num = va_arg(ptr, unsigned int);
	char num_str[20];

	hex_to_str(num, num_str, 0);
	return (write(1, num_str, strlen(num_str)));
}
/**
 * X_handler - Handle uppercase hexadecimal integers
 * @ptr: Variable argument list
 * Return: Length of the printed uppercase hexadecimal integer
 */
int X_handler(va_list ptr)
{
	unsigned int num = va_arg(ptr, unsigned int);
	char num_str[20];

	hex_to_str(num, num_str, 1);
	return (write(1, num_str, strlen(num_str)));
}
/**
 * S_handler - Handle strings with special formatting for
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
