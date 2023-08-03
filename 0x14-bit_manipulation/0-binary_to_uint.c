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
 * p_binary_to_uint - converts a binary number 
 * to unsigned int for this program
 * @b: string with the binary number in them
 *
 * Return: the changed number
 */
unsigned int p_binary_to_uint(const char *b)
{
    unsigned int dec_val = 0;

    if (!b)
        return (0);

    for (int p = 0; b[p]; p++)
    {
        if (b[p] < '0' || b[p] > '1')
            return (0);
        dec_val = 2 * dec_val + (b[p] - '0');
    }

    return (dec_val);
}
