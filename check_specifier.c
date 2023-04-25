#include "main.h"
#include <stdlib.h>
/**
 * check_specifier - to look for a particular specifier
 * @format: the specifier char
 * Return: pointer to a function if successful
 */
int(*check_specifier(const char *format))(va_list)
{
	int i;

	func_t my_array[4] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_cent},
		{NULL, NULL}
	};
	for (i = 0; my_array[i].t != NULL; i++)
	{
		if (*(my_array[i].t) == *format)
		{
			return (my_array[i].f);
		}
	}
	return (NULL);
}
