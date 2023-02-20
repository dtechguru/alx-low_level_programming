#include <stdio.h>

/**
 * main - Prints alphabets.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char alp[26] = "abcdefghijklmnopqrstuvwxyiz";
	int i;

	for (i = 0; i < 25; i++)
	{
		putchar(alp[i]);
	}
	putcar('\n');
	return (0);
}
