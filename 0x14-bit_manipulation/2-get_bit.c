#include "main.h"


/**

 * get_bit - should return the value of a bit at an index in a decimal number of the below program.

 * @n: number's that are to be search

 * @index: give the index of the bit here.

 *

 * Return: the value of bit int the programmem

 */

int get_bit(unsigned long int n, unsigned int index)

{

	int bit-val;


	if (index > 63)

		return (-1);


	bit-val = (n >> index) & 1;


	return (bit-val);

}
