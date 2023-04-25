#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
/**
 * this is a function that takes an input of
 * character pointer and return a pointer to a function
 * that takes in va_list as the argument and 
 * returns an int
 */
int (*check_specifier(const char*))(va_list);

/**
 * struct func - struct for specifier to a pointer
 * @t: character to compare
 * @f: function to handle printing
 */
typedef struct func
{
	char *t;
	int (*f)(va_list);
} func_t;

/*Function prototypes for the specifiers*/
int print_char(va_list args);
int print_str(va_list args);
int print_cent(va_list args);

#endif

