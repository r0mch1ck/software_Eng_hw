#include "io.h"
#include <stdio.h>

void read_line(FILE *file, char *line, size_t size) {
    if (fgets(line, size, file) == NULL) {
        line[0] = '\0';
    }
}

void write_line(FILE *file, const char *line) {
    fprintf(file, "%s\n", line);
}
