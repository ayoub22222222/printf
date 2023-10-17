#include "main.h"
/**
 * _printf - Entry point
 * @format: the last input
 * @...: infinit number of argument
 * Return: print
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int count = 0;

	while (*format != '\0')
	{
	if (*format != '%')
	{
	putchar(*format);
	count++;
	}
	else
	{
	switch (*++format)
	{
	case 'd':
	count += fprintf(stdout, "%d", va_arg(args, int));
	break;
	case 'i':
	count += fprintf(stdout, "%d", va_arg(args, int));
	break;
	default:
	putchar('%');
	putchar(*format);
	count += 2;
	break;
	}
	}
	format++;
	}

	va_end(args);
	return (count);
}
