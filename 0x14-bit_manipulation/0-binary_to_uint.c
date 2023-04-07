#include "main.h"

/**
 * function that converts a binary number to an unsigned int.
 * @b: is the binary string
 * Return: the converted number, or 0 if there is one or more chars in the string b
 * that is not 0 or 1 or if b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int j = 0, decimal = 0;

	if (b == NULL)
		return (0);
	while (b[j] != '\0')
	{
		if (b[j] != '0' && b[j] != '1')
			return (0);
		decimal <<= 1;
		if (b[j] == '1')
			decimal ^= 1;
		j++;
	}
	return (decimal);
}
