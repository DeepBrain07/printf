#include "main.h"

/**
*_printf - works like printf
*@format: a character string
*@...: other parameters
*Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
	unsigned int i, j, k, count;
	char formatList[] = "csdi";
	char *str, str2[2], ch, *str1, myInt[2];
	char* itoa(int, char* , int);
	va_list list;

	for (count = 0; format[count]; count++)
		;
	str = malloc(sizeof(char) * (count + 1));
	if (str == NULL)
	{
		free(str);
		return (-1);
	}
	for (i = 0; format[i]; i++)
		str[i] = format[i];
	str[i] = '\0';
	va_start(list, format);

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '%')
			for (j = 0; formatList[j]; j++)
			{
				if (str[i + 1] == 'c')
				{
					ch = va_arg(list, int);
					str2[0] = ch;
					write(1, str2, 1);
					i++;
				}
				else if (str[i + 1] == 's')
				{
					str1 = va_arg(list, char *);
					for (k = 0; str1[k]; k++)
						;
					write(1, str1, k);
					i++;
				}
				else if (str[i + 1] == 'd' || str[i + 1] == 'i')
				{
					itoa(va_arg(list, int), myInt, 10);
					write(1, myInt, 1);
					i++;
				}
			}
		else
		{
			str2[0] = str[i];
			write(1, str2, 1);
		}
	}

	va_end(list);
	free(str);

	return (count);
}
