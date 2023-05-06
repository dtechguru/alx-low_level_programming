#ifndef MAIN_H

#define MAIN_H


unsigned int binary_to_uint(const char *b);
/*(0)*/
void print_binary(unsigned long int n);
/*(1.1)*/
int get_bit(unsigned long int n, unsigned int index);
/*(2.10)*/
int set_bit(unsigned long int *n, unsigned int index);
/*(3.11)*/
int clear_bit(unsigned long int *n, unsigned int index);
/*(4.100)*/
unsigned int flip_bits(unsigned long int n, unsigned long int m);
/*(5.101)*/
int _atoi(const char *s);

int _putchar(char c);

int get_endianness(void);
/*(6.Endianess)*/

#endif
