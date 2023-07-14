#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file then  print to STDOUT in teh program.
 * @filename: text file being read in the program code 
 * @letters: number of letters to be read in the algorithm
 * Return: w- actual number of bytes read and printed for this program code
 *        0 when function fails or filename is NULL.. *dtechguru*
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    char *p;
    ssize_t fd;
    ssize_t w;
    ssize_t t;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (0);
    p = malloc(sizeof(char) * letters);
    t = read(fd, p, letters);
    w = write(STDOUT_FILENO, p, t);

    free(p);
    close(fd);
    return (w);
}

/*Dtechguru*/
