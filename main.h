#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct {
	char specify;
	void (*handler)(va_list);
} Handle_Format;

Handle_Format *get_handle_format();

void c_handler(va_list ptr);
void s_handler(va_list ptr);
void b_handler(va_list ptr);
void d_handler(va_list ptr);
int _printf(const char *format, ...);
int len_str(char *P);
void num_to_str(int num, char *str);
void int_conversion(int number);
void _convert_to_binary(unsigned int num);

#endif /* MAIN_H */
