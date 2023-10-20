#include "main.h"
/**
 * p_handler - Handle pointers (print in hexadecimal).
 * @ptr: Variable argument list.
 * Return: Length of the printed pointer.
 */
int p_handler(va_list ptr)
{
	void *pt = va_arg(ptr, void*);
	char addr_str[20];
	unsigned long address = (unsigned long)pt;
	int length;

	if (pt == NULL)
	{
		return (write(1, "(nil)", 5));
	}
	write(1, "0x", 2);
	length = hex_to_str(address, addr_str, 0);
	write(1, addr_str, length);
	return (length + 2);
}
/**
 * r_handler - Print reversed string.
 * @ptr: Pariable argument list.
 * Return: Length of the reversed string.
 */
int r_handler(va_list ptr)
{
	char *str = va_arg(ptr, char *);
	int length = strlen(str), Q;

	for (Q = length - 1; Q >= 0; Q--)
	{
		write(1, &str[Q], 1);
	}
	return (length);
}
/**
 * R_handler - Print Rot13'ed string.
 * @ptr: Variable argument list.
 * Return: Length of the Rot13'ed string.
 */
int R_handler(va_list ptr)
{
	char *str = va_arg(ptr, char *);
	int length = strlen(str), Q;
	char R;

	for (Q = 0; length > Q; Q++)
	{
		R = str[Q];
		if (R >= 'a' && R <= 'z')
		{
			R = ((R - 'a' + 13) % 26) + 'a';
		}
		else if (R >= 'A' && R <= 'Z')
		{
			R = ((R - 'A' + 13) % 26) + 'A';
		}
		write(1, &R, 1);
	}
	return (length);
}
