/*
*****************************************
                                        *
					*
        Dtechguru code			*
                                        *
					*
*****************************************
*/

#ifndef MAIN_H
#define MAIN_H

int p_get_bit(unsigned long int n, unsigned int index);
int p_set_bit(unsigned long int *n, unsigned int index);
int p_clear_bit(unsigned long int *n, unsigned int index);
unsigned int p_flip_bits(unsigned long int n, unsigned long int m);
int _atoi(const char *s);
int _putchar(char c);
int p_get_endianness(void);
unsigned int p_binary_to_uint(const char *b);
void p_print_binary(unsigned long int n);

#endif
