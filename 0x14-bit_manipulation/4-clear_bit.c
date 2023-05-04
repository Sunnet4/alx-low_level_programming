#include "main.h"
#include <stdlib.h>
/**
 * clear_bit - to set the value of a bit to 0 at a certain index
 * @n: parameter to set at certain parameter
 * @index: index at the set parameter
 *
 * Return: 1 if success, -1 if error occurred
 * Author: Awolaja
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > sizeof(n) * 8)
		return (-1);
	*n &= ~(1 << index);
	return (1);
}
