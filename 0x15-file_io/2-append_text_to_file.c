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

int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
/*Dtechguru*/
	o = open(filename, O_WRONLY | O_APPEND);
	w = write(o, text_content, len);

	if (o == -1 || w == -1)
		/*Dtechguru*/
		return (-1);

	close(o);

	return (1);
}


