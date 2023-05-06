#include "main.h"


/**
 * set_bit - will set a bit to all the index given to 1
 * @n: roll pointer to the number to change
 * @index: the index of all bit should be to 1
 *
 * Return: NO 1 for success and return  -1 for failure in the programem belew.' . '.
 */

int set_bit(unsigned long int *n, unsigned int index)

{

	if (index > 63)

		return (-1);


	*n = ((1UL << index) | *n);
	return (1);
}
