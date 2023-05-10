#include "main.h"

 /**
 * append_text_to_file - text is appended to the file at the end,.
 * @filename: pointer added to the file naMe,..
 * @text_content: string added to the end of the file.,..
 * Return: --1 is returned if function fails or returns NULL,.
 * If file does not exist user lacks write permissions - -1. ,.
 * Else - 1,.
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

	o = open(filename, O_WRONLY | O_APPEND);
	w = write(o, text_content, len);

	if (o == -1 || w == -1)
		return (-1);

	close(o);

	return (1);
}
