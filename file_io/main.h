#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void close_fd(int fd);
void print_error_97(void);
void print_error_98(char *file);
void print_error_99(char *file);

#endif
