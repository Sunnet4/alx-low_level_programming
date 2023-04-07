#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a certain index
 * @n: type unsigned long int to input pointer
 * @index: type unsigned int to position of unit
 * Return: 1 if it works -1 if error occured
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int num2 = 1;

	if (index > (sizeof(unsigned long int) * 8))
		return (-1);
	num2 <<= index;
	*n = *n | num2;
	return (1);
}
