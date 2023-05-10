#include "main.h"

/**
 * get_endianness - this should check if a machine is little or big endian .'.'
 * Return: the num 0 for big and 1 if otherwise "little".'.'.
 */
int get_endianness(void)
{
	unsigned int p = 1;
	char *c = (char *) &p;

	return (*c);
}
