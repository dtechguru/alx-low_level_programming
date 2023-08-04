/*
 * ****************************************
 *                                        *
 *                                        *
 *            Author: Dtechguru           *
 *                                        *
 *                                        *
 * ****************************************
 */

#include "main.h"

/**
 * set_bit - orders a bit at a given index to 1
 * @n: pointer to the number to change or converted
 * @index: the index of the bit is to be set to (1)
 *
 * Author: Dtechguru
 * Return: 1 for success of the program, -1 if otherwise
 */
int set_bit(unsigned long int *n, unsigned int index)
{
    if (index > 63)
        return (-1);

    *n = ((1UL << index) | *n);
    return (1);
}
