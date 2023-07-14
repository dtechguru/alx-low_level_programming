/*2-append_text_to_file.c*/
/*Dtechguru*/

#include "main.h"

/**
 * append_text_to_file - Appends wprds at the end of  file in the program.
 * @filename: A pointer to the name of the file.
 * @text_content: a pointer allocated to the string to add to the end of the file for hte program.
 *
 * Return: If the function gets sisrupted  or filename is empty - -1.
 *         If the file is not available the user lacks write permissions - -1.
 *         Otherwise - 1.
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

/*Dtechguru*/
