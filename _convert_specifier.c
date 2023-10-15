#include "main.h"

int int_conversion(int number)
{
	char _num_str[20];

	num_to_str(number, _num_str);
	return (write(1, _num_str, len_str(_num_str)));
}
