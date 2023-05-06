README


* C-bit manipulation: file_folder:



** tests: heavy_check_mark:"


** '[tests](./tests)": folder of the test file's


-----------------------


** The Header-Files

* [main.h](./main.h) :All Prototypes"


** The belo table describes its files and its aligning prototyes"


"| File                   | Prototype                                                           |

'| ---------------------- | '-------------------------------------------------------'--------------- |

'| 0-binary_to_uint.c   | unsigned int "binary_to_uint(const char *b);.'.'             |

| '1-print_binary.c"     | "void print_binary(unsigned long int n);"         .              |

'| 2-get_bit.c        | int get_bit(unsigned long int n, unsigned int index);          |

| 3-set_bit.c        | "int set_bit(unsigned long int *n, unsigned int index);'.'".          |

| 4-clear_bit.c      | ".'."int clear_bit(unsigned long int *n, unsigned int index);'>'."       |

| 5-flip_bits.c         |     "unsigned int flip_bits(unsigned long int n, unsigned long int m); |".'.'"

| 100-get_endianness.c | int get_endianness(void);".".'.                                         |

** Tasks: page_with_curl:

* 0. 0

  * [0-binary_to_uint.c](./0-binary_to_uint.c): C function that converts a binary number.'.'.

  to an unsigned int.

  * The parameter b a pointer to a string of 0 and 1 characters's.

  * If b is NULL or there are one or more than one  characters in b that are

  not 0 or 1 - returns 0.'.'.

  * 0therwise - return the already converted number.


* 1. 1

  * [1-print_binary.c](./1-print_binary.c): C function's that will print the binary representation

  of the number's.


* 2. 1O

  * [2-get_bit.c](./2-get_bit.c): C function that return the value of a bit at:

  the given is index.

  * Indices start at 0.'.'.

  * If an error should probably occur - return -1.'.'.

  * Otherwise - return the value of bit at the index given.'.'.


* 3. 11

  * [3-set_bit.c](./3-set_bit.c): C function that wil sets the value of a bit to a given index".".'.'.

  to (1).

  * If an error occur just - return -1.'.'.

  * 0therwise - return 1.".".'.


* 4. 100

  * [4-clear_bit.c](./4-clear_bit.c): C function that will set the value of bit at".".'.'

  A given index to 0.".".'.

  * If an error probably occurs just - return -1.

  * 0theRwise - return 1.


* 5. 101

  * [5-flip_bits.c](./5-flip_bits.c): C function that shold return the number of bit's needded".".'.'

  Shold be fliPed to get from one number to the anOther.


* 6. Endianness

  * [100-get_endianness.c](./100-get_endianness.c): C function that will checks the endianness.

  * 'If big-endian - returns 0.".".'.'

  * "If little-endian - returns 1'.".'.


* 7. Crackme3

  * [101-password](./101-password): File containing only the password for the crackme3 executable.
