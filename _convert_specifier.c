#include "main.h"

void int_conversion(int number)
{
	char _num_str[20];

	num_to_str(number, _num_str);
	write(1, _num_str, len_str(_num_str));
}
