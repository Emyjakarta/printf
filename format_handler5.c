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

	write(1, "0x", 2);
	length = hex_to_str(address, addr_str, 0);
	write(1, addr_str, length);
	return (length + 2);
}
