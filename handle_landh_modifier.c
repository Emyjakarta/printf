#include "main.h"
/**
 * handle_l_modifier-handle l modifier for integer conversions
 * @specifier: the conversion specifier
 * @ptr: variable argument list
 * Return:Number of characters written
 */
int handle_l_modifier(const char specifier, va_list ptr)
{
	char buffer[20];
	int length = 0;
	long numb;
	unsigned long num;

	switch (specifier)
	{
		case 'd':
		case 'i': {
			numb = va_arg(ptr, long), length = int_conversion(numb);
			break;
		}
		case 'u': {
			num = va_arg(ptr, unsigned long), length = u_num_to_str(num, buffer);
			write(1, buffer, length);
			break;
		}
		case 'o': {
			num = va_arg(ptr, unsigned long), length = octal_to_str(num, buffer);
			write(1, buffer, length);
			break;
		}
		case 'x': {
			num = va_arg(ptr, unsigned long), length = hex_to_str(num, buffer, 0);
			write(1, buffer, length);
			break;
		}
		case 'X': {
			num = va_arg(ptr, unsigned long), length = hex_to_str(num, buffer, 1);
			write(1, buffer, length);
			break;
		}
		default:
			return (-1);
	}
	return (length);
}
#include "main.h"
/**
 * handle_h_modifier-handle h modifier for integer conversions
 * @specifier: the conversion specifier
 * @ptr: variable argument list
 * Return:Number of characters written
 */
int handle_h_modifier(const char specifier, va_list ptr)
{
	char buffer[20];
	int length = 0;
	short numb;
	unsigned short num;

	switch (specifier)
	{
		case 'd':
		case 'i': {
			numb = va_arg(ptr, int), length = int_conversion(numb);
			break;
		}
		case 'u': {
			num = va_arg(ptr, unsigned int), length = u_num_to_str(num, buffer);
			write(1, buffer, length);
			break;
		}
		case 'o': {
			num = va_arg(ptr, unsigned int), length = octal_to_str(num, buffer);
			write(1, buffer, length);
			break;
		}
		case 'x': {
			num = va_arg(ptr, unsigned int), length = hex_to_str(num, buffer, 0);
			write(1, buffer, length);
			break;
		}
		case 'X': {
			num = va_arg(ptr, unsigned int), length = hex_to_str(num, buffer, 1);
			write(1, buffer, length);
			break;
		}
		default:
			return (-1);
	}
	return (length);
}
