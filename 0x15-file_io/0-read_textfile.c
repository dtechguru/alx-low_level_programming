#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Check book, print for screen.
 * @filename: Name of book we wan read
 * @letters: Number of letters we fit read
 * Return: w - How many letters we fit read and show for screen
 *        0 - If e no work or filename null.
 * Author: Dtechguru
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	/*Dtechguru*/
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}

