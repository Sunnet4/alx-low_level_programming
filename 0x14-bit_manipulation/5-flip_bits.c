#include "main.h"

/**
 * flip_bits - finds # of bits that need to be flipped to make new number
 * @n: number one to be flipped
 * @m: number two to be flipped to
 * Return: number of bits flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int new1;
	unsigned int flip_bit;

	new1 = n ^ m;
	flip_bit = 0;
	while (new1 > 0)
	{
		if ((new1 & 1) != 0)
			flip_bit++;
		new1 = new1 >> 1;
	}
	return (flip_bit);
}
