#include "main.h"

/**
*_putchar - works like putchar function
*@c: a character
*Return: '0' on success
*/
int _putchar(char c)
{
	char ch[2];
	ch[0] = c;
	write(1, ch, 1);
	return (0);
}
