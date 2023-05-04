#include"main.h"

/**
 * get_bit - to returns the value of a bit at a certain index.
 * @n: number to check bits for
 * @index: the index to check bit
 *
 * Return: value of bit, or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int divide, check;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	divide = 1 << index;
	check = n & divide;
	if (check == divide)
		return (1);
	return (0);
}
