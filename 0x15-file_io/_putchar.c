#include "main.h"
#include <unistd.h>
/**
* _putchar - types the character c into stdout
* @c: thecharacter'saretobeprinted
* Return: 1ifcodeisasuccess
* On error, -1 istobe returned, and errno isgoingtobe set appropriately.
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}
