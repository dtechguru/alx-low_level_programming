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
 * clear_bit - orders the value of a given bit to 0
 * @n: pointer to the number to change in the program
 * @index: index of the bit to be cleared
 *
 * Return: 1 if the program happens to be a success, -1 if otherwise
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
    if (index > 63)
        return (-1);

    *n = (~(1UL << index) & *n);
    return (1);
}
