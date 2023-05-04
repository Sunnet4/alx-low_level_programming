#include "main.h"

/**
 * binary_to_uint - to convert a binary number to unsigned int.
 * @b: pointer of the string containing a binary number
 *
 * Return: unsigned int with decimal value of  binary number
 * hence 0 if  error
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int digit;

	digit = 0;
	if (!b)
		return (0);
	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
	}
	for (i = 0; b[i] != '\0'; i++)
	{
		digit <<= 1;
		if (b[i] == '1')
			digit += 1;
	}
	return (digit);
}
