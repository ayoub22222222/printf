#include "main.h"
/**
 * _printf - mimic print function
 * @format: the last input
 * @...: infinit number of argument
 * Return: print
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int printed_chars = 0;
	va_list args;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			printed_chars += format_handler(format[i], args);
		}
		else
		{
			printed_chars += _putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (printed_chars);
}
