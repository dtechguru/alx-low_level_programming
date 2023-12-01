#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/*Dtechguru*/
char *create_buffer(char *file);
void close_file(int fd);


/**
 * creates_buffer - E create space for 1024 characters.
 * @file: The name of the file wey this buffer dey store chars.
 *
 * Return: E go return pointer to the newly-created buffer.
 * Author: Dtechguru
 */

char *creates_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}
/**
 * close_file - E dey close file hand.
 * @fd: The file hand wey dem wan close.
 * Author: Dtechguru
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - E dey copy the content of one file enta anoda file.
 * @argc: The number of arguments wey dem give the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 if e succeed.
 *
 * Description: If the argument count no follow - make e comot with code 97.
 * If file_from no dey or e no gree read - make e comot with code 98.
 * If e no fit create or write for file_to - make e comot with code 99.
 * If e no fit close file_to or file_from - make e comot with code 100.
 * Author: Dtechguru
 */


int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
/*Dtechguru*/
		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);
/*Dtechguru*/
	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}

