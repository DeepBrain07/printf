#include "main.h"

/**
*_printf - works like printf
*@format: a character string
*@...: other parameters
*Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
	unsigned int i, k, count;
	char str2[2], ch, *str1;
	va_list list;

	for (count = 0; format[count]; count++)
		;
	va_start(list, format);

	if (format == NULL)
	{
		write(1, "", 1);
		return (0);
	}
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				ch = va_arg(list, int);
				str2[0] = ch;
				write(1, str2, 1);
				i++;
			}
			else if (format[i + 1] == 's')
			{
				str1 = va_arg(list, char *);
				for (k = 0; str1[k]; k++)
					;
				write(1, str1, k);
				i++;
			}
			else if (!(format[i + 1]))
				write(1, "", 1);
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				print_de(va_arg(list, int));
				i++;
			}
			else
			{
				str2[0] = format[i];
				write(1, str2, 1);
				i++;
			}
		}
		else
		{
			str2[0] = format[i];
			write(1, str2, 1);
		}
	}

	va_end(list);

	return (count);
}
