#include "main.h"

/**
*print_de - prints a decimal
*@n: an integer
*Return: nothing
*/
void print_de(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n / 10)
		print_de(n / 10);
	_putchar((n % 10) + 48);
}
