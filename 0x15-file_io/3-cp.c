/*Dtechguru*/
/*3-cp.c*/

#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - assigns 1024 bytes for a buffer.
 * @file: The save namme of the file buffer is keeping chars for.
 *
 * Return: A pointer to the newly-assigned buffer.
 */
char *create_buffer(char *file)
{
    char *p;

    p = malloc(sizeof(char) * 1024);

    if (p == NULL)
    {
        dprintf(STDERR_FILENO,
                "Error: Can't write to %s\n", file);
        exit(99);
    }

    return (p);
}

/**
 * close_file - exits file explanators.
 * @fd: tHe file's descriptor to be exited.
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
 * main - makes duplicates of the contents of a file and allocates  to another file.
 * @argc: The amount of arguments supplied for the program.
 * @argv: An array of pointers allocated to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is wrongly inputed or not even correct - exit code 97.
 *              If file_from is not available  or cannot be gone through - crash code 98.
 *              If file_to cannot be made or written to - exit code 99.
 *              If file_to or file_from cannot be ended  - exit code 100.
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

/*Dtechguru*/
