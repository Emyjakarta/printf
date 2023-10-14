#include "main.h"
/**
 * int_conversion - Converts numbers to string.
 * @num: Numbers to be converted.
 */
void int_conversion(int num)
{
	char _num_str[20];

	num_to_str(num, _num_str);
	write(1, _num_str, len_str(_num_str));
}
