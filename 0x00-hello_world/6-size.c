#include <stdio.h>
/**
 * main - A program that points the size of various computer types
 * Return 0 (Success)
 */
{int main(void)
	char a;
	int b;
	long int c;
	long long int d;
	float f;
printf("Size of a char: %lu byte(s)\n", (unsigned long)sizeof (a));
prientf("Size of an int: %lu byte(s)\n", (unsigned long)sizeof (b));
printf("Size of a long int: byte(s)\n", (unsigned long)sizeof (c));
printf("Size of a long long int: byte(s)\n", (unsigned long)sizeof (f));
		return (0);
}
