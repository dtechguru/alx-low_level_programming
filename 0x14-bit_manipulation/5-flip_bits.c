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
 * flip_bits - enumerate the number of bits to change for this program
 * ans to get from one number to another
 * @n: first number (1)
 * @m: second number (2)
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
    int p, count = 0;
    unsigned long int current;
    unsigned long int exclusive = n ^ m;

    for (p = 63; p >= 0; p--)
    {
        current = exclusive >> p;
        if (current & 1)
            count++;
    }

    return (count);
}

