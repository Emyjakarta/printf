#include "main.h"

void c_handler(va_list ptr) {
	char c = va_arg(ptr, int);
	write(1, &c, 1);
}

void s_handler(va_list ptr) {
	char *str = va_arg(ptr, char *);
	int length = len_str(str);
	write(1, str, length);
}

void b_handler(va_list ptr) {
	unsigned int num = va_arg(ptr, unsigned int);
	_convert_to_binary(num);
}

void d_handler(va_list ptr) {
	int num = va_arg(ptr, int);
	int_conversion(num);
}

Handle_Format handle_format[] = {
	{'c', c_handler},
	{'s', s_handler},
	{'d', d_handler},
	{'b', b_handler},
	{'%', NULL},
	{'\0', NULL},
};

Handle_Format *get_handle_format()
{
	return (handle_format);
}
