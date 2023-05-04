#include "main.h"

/**
 * _power - calculates base power
 * @base: base of exponent
 * @power: power of the exponent
 *
 * Return: value of base  power
 */
unsigned long int _power(unsigned int base, unsigned int power)
{
	unsigned long int digit;
	unsigned int i;

	digit = 1;
	for (i = 1; i <= power; i++)
		digit *= base;
	return (digit);
}

/**
 * print_binary - prints number in a binary notation
 * @n: number to be printed
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int divide, check;
	char sign;

	sign = 0;
	divide = _power(2, sizeof(unsigned long int) * 8 - 1);
	while (divide != 0)
	{
		check = n & divide;
		if (check == divide)
		{
			sign = 1;
			_putchar('1');
		}
		else if (sign == 1 || divide == 1)
		{
			_putchar('0');
		}
		divide >>= 1;
	}
}
