#include "main.h"

/**
 * get_endianness - to check the endianness
 *
 * Return: 0 if big endian, else 1 if little endian
 */
int get_endianness(void)
{
	int p;
	char *q;

	p = 1;
	q = (char *)&p;
	return (*q);
}

