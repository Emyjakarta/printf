#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
/**
 * struct Handle_Format - renaming struct to Handle_Format
 * @specify: first element of type char
 * @handler: function pointer that returns void
 *
 * Description: Longer description
 */
typedef struct Handle_Format
{
	char *specify;
	int (*handler)(va_list);
} Handle_Format;

int get_handle_format(const char *format, unsigned int *length, va_list ptr);
int c_handler(va_list ptr);
int s_handler(va_list ptr);
int b_handler(va_list ptr);
int d_handler(va_list ptr);
int percent_handler(va_list);
int _printf(const char *format, ...);

#endif /* MAIN_H */
