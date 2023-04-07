#include "main.h"

/**
 * clear_bit - sets value of bit to 0 at given index
 * @n: integer to find bit to convert
 * @index: index of bit to convert
 * Return: 1 if it worked, or -1 if an error occurred
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int swap1 = 1;

	if (index > (sizeof(unsigned long int) * 8))
		return (-1);
	swap1 <<= index;
	*n = *n & ~swap1;
	return (1);
}
