#ifndef IO_H
#define IO_H

#include <stdio.h>

void read_line(FILE *file, char *line, size_t size);
void write_line(FILE *file, const char *line);

#endif // IO_H
