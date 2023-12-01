#include "main.h"
/*Dtechguru*/

/**
 * create_file - E fit create file for us.
 * @filename: Pointer to the name of the file wey we wan create.
 * @text_content: Pointer to string wey we wan write for the file.
 *
 * Return: If e no work - -1.
 *         If e work - 1.
 * Author: Dtechguru
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	if (filename == NULL)
		return (-1);

	/*Dtechguru*/
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(fd, text_content, len);

	if (fd == -1 || w == -1)
		return (-1);
	/*Dtechguru*/

	close(fd);

	return (1);
	/*Dtechguru*/
}

