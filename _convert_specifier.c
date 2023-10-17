#include "main.h"
/**
 * int_conversion - Takes a number to be converted to string
 * @num: number to be converted
 * Return:converted number string
 */
int int_conversion(int num)
{
	char _num_str[20];

	num_to_str(num, _num_str);
	return (write(1, _num_str, strlen(_num_str)));
}
