#include "main.h"
/**
 * int_conversion-takes a number to be converted to string
 * @number: number to be converted
 * Return:converted number string
 */
int int_conversion(int number)
{
	char _num_str[20];

	num_to_str(number, _num_str);
	return (write(1, _num_str, strlen(_num_str)));
}
