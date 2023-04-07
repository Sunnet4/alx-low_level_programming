#include "main.h"

/**
 * get_endianness - find the type of endianness
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *y = (char *)&i;

	if (*y)
		return (1);
	else
		return (0);
}
