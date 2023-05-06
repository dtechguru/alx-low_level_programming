#include "main.h"

/**
 * clear_bit - should set the value of all given bit to 0.'.'.
 * @n: pointer are assigned to the number to change.'.'.
 * @index: the index of the bit to be cleared.'.'.
 *
 * Return: 1 for success and -1 for otherwise'.'.'
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 71)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
