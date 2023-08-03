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
 * p_get_endianness - checks if a machine is little or big endian
 * Return: 0 if big, and 1 for little
 */
int p_get_endianness(void)
{
    unsigned int p = 1;
    char *c = (char *)&p;

    return (*c);
}
