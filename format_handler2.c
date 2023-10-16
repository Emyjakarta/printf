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
	int length;

	if (number == 0)
	{
		u_num_str[0] = '0';
		u_num_str[1] = '\0';
		return (write(1, u_num_str, 1));
	}
	length = u_num_to_str(number, u_num_str);
	return (write(1, u_num_str, length));
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

	octal_to_str(number, num_str);
	return (write(1, num_str, strlen(num_str)));
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

	hex_to_str(number, num_str, 0);
	return (write(1, num_str, strlen(num_str)));
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

	hex_to_str(number, num_str, 1);
	return (write(1, num_str, strlen(num_str)));
}
