#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...);
int len_str(char *P);
void num_to_str(int num, char *str);
void int_conversion(int number);
#endif /* MAIN_H */
