#include "main.h"

/**
 * flip_bits - to count the number of bits to be changed
 * to get from one number to another number
 * @n: first number
 * @m: second number
 *
 * Return: the number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int k, count = 0;
	unsigned long int recent;
	unsigned long interchange = n ^ m;

	for (k = 63; k >= 0; k--)
	{
		recent = interchange >> k;
		if (recent & 1)
			count++;
	}

	return (count);
}
