/*
*****************************************
					*
					*
	Dtechguru code's		*
					*
					*
*****************************************
*/

#include "main.h"
#include <unistd.h>
/**
 * _putchar - writes the character c to stdout meaning (standard output).
 * @c: The character to be printed
 *
 * Return: 1 if teh program is a success.
 * On error, -1 is to be returned, and errno is set correctly and accordingly
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
