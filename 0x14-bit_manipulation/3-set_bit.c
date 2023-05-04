#include "main.h"

/**
 * set_bit - to set the value of a bit to 1 at a certain index.
 * @n: number to set
 * @index: index at which to set bit
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int fix;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	fix = 1 << index;
	*n = *n | fix;
	return (1);
}
