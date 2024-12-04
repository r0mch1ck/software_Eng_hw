#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdbool.h>

#define MAX_NUMBERS 10000

FILE *open_file(const char *filename, const char *mode);

bool read_line(FILE *file, int *numbers, int *num_count, int max_count);

void write_line(FILE *file, const int *numbers, int num_count);

#endif // IO_H
