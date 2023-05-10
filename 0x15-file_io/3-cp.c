#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

 /**
 * create_buffer - allocate 1024 bytes to  buffer,.
 * @file: name of the files buffer is stored in chars for,.
 * Return: A pointer is allocated to the newly-allocated buffer,.
 */

char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}
	return (buffer);
	}

 /**
 * close_file - close all file descRIptors in the program,.
 * @fd:  file descriptor to be closed,.
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
 * main - the content of the file is copied to another file in the progam,.
 * @argc: The figures of arguments is supplied in the program.
 * @argv: arrays of pointers to the arguments in the program,.
 * Return: num 0 on success.
 * Description: If any argument count should be incorrect - exit code 97.
 *  If file_from does not exist or cannot be read - simply exit code 98,.
 *  If file_to isn't able to be made or wrote to - exit code 99,.
 * If file_to or file_from cant be closed - exit code 100,.
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

		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
