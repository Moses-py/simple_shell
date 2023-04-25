#include "main.h"

/**
 *_printf- function prints formatted text to standard output
 *@format: format string
 */

void _printf(char *format, ...)
{
	va_list args;

	va_start(args, format);
	vfprintf(stdout, format, args);
	va_end(args);
}
