#include <stdio.h>
#include "main.h"

/**
 * binary_to_uint - converts a binary number into an unsigned int
 * @b: type const char pointer of one bit
 * Return: converted number, or 0 if one or more char in str b
 * that is not 0 or 1
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int n = 0;
	unsigned int decimal = 0;

	if (b == NULL)
		return (0);
	while (*(b + n) != '\0')
	{
		if (*(b + n) != '0' && *(b + n) != '1')
			return (0);
		decimal <<= 1;
		if (*(b + n) == '1')
			decimal ^= 1;
		n++;
	}
	return (decimal);
}
