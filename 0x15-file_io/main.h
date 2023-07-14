#ifndef MAIN_H
#define MAIN_H

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/*Dtechguru*/
ssize_t read_textfile(const char *filename, size_t letters);
/*Dtechguru*/
int create_file(const char *filename, char *text_content);
/*Dtechguru*/
int append_text_to_file(const char *filename, char *text_content);

#include <sys/types.h>
#endif

/*Dtechguru*/
