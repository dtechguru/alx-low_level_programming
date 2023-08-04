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
 * get_bit.c - returns the digit of a bit at an index in a decimal value
 * @n: number to search for
 * @index: index of the bit in the program
 *
 * Author: Dtechguru
 * Return: the digit for the biit
 */
int get_bit(unsigned long int n, unsigned int index)
{
    int bit_val;

    if (index > 63)
        return (-1);

    bit_val = (n >> index) & 1;

    return (bit_val);
}
