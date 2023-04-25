#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
/**
 * _printf - function to print different formats
 * @format: the format of the character
 * Return: 0
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	int value = 0;
	int (*f)(va_list);

	va_list args;

	va_start(args, format);

	/*Prevents Parsing a NULL pointer*/
	if (format == NULL)
		return (-1);

	/*Print each character of string*/
	while (format[i])
	{
		if (format[i] != '%')
		{
			value = write(1, &format[i], 1);
			count = count + value;
			i++;
		}
		if (format[i] == '%')
		{
			f = check_specifier(&format[i + 1]);
			if (f != NULL)
			{
				value = f(args);
				count += value;
				i = i + 2;
				continue;
			}
			if (format[i + 1] != '\0')
			{
				value = write(1, &format[i + 1], 1);
				continue;
			}
		}
	}
	return (count);
}
