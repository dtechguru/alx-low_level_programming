#include "main.h"

/**
 * flip_bits - counts number of bits that are to be change in the programmeme
 * to get from one number to the other in the programmeme
 * @n: firsT(1st) nuMber()
 * @m: seCond(2nd) nuMber()
 *
 * RetUrn: the number of the bits to change in the program below.'.'.
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
