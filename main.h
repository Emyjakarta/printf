#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 1024
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
int u_handler(va_list ptr);
int o_handler(va_list ptr);
int x_handler(va_list ptr);
int X_handler(va_list ptr);
int S_handler(va_list ptr);
int _printf(const char *format, ...);
int len_str(char *P);
int int_conversion(int number);
int num_to_str(int num, char *str);
unsigned int u_num_to_str(unsigned int num, char *str);
int octal_to_str(unsigned int num, char *str);
int hex_to_str(unsigned long num, char *str, int upper);
int _itoa(int num, char *str, int base);
int print_hex_value(char value);
int p_handler(va_list ptr);
int handle_l_modifier(const char specifier, va_list ptr);
int handle_h_modifier(const char specifier, va_list ptr);

#endif /* MAIN_H */
