#include "main.h"
#include <stdlib.h>
#include <unistd.h>
/**
 * print_char - function to print a character
 * @args: list of arguments
 * Return: character
 */
int print_char(va_list args)
{
	char c = (char)va_arg(args, int);
	int count = 0;

	if (c)
	{
		count = write(1, &c, 1);
		return (count);
	}
	return (0);
}

/**
 * print_str - function to print out a string
 * @args: list of arguments
 * Return: string
 */
int print_str(va_list args)
{
	char *str = va_arg(args, char *);
	int i = 0;
	int r_val = 0;

	if (str)
	{
		while (str[i] != '\0')
		{
			putchar(str[i]);
			r_val += 1;
		}
	}
	return (r_val);
}

/**
 * print_cent - function to print percentage sign
 * @args: list of arguments
 * Return: percentage sign
 */
int print_cent(va_list args)
{
	(void)args;
	return (write(1, "%%", 1));
}
