#include "io.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#define LINE_SIZE 100000
#define MAX_NUMBERS 10000

FILE *open_file(const char *filename, const char *mode) {
    FILE *file = fopen(filename, mode);
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    return file;
}

bool read_line(FILE *file, int *numbers, int *num_count, int max_count) {
    *num_count = 0;
    long long buffer;

    char line[LINE_SIZE];
    if (fgets(line, LINE_SIZE, file) == NULL) {
        return false;
    }

    for (int i = 0; line[i] != '\0'; i++) {
        if (!(isdigit(line[i]) || line[i] == ' ' || line[i] == '-' || line[i] == '\n')) {
            return false;
        }
    }

    char *token = strtok(line, " \t\n");
    while (token != NULL) {
        if (sscanf(token, "%lld", &buffer) != 1) {
            return false;
        }

        if (buffer < INT_MIN || buffer > INT_MAX) {
            return false;
        }

        if (*num_count >= max_count) {
            return false;
        }

        numbers[*num_count] = (int) buffer;
        (*num_count)++;

        token = strtok(NULL, " \t\n");
    }

    return *num_count > 0;
}


void write_line(FILE *file, const int *numbers, int num_count) {
    if (num_count == 0) {
                fprintf(file, "\n");
    } else {
        for (int i = 0; i < num_count; i++) {
            fprintf(file, "%d", numbers[i]);
            if (i < num_count - 1) {
                fprintf(file, " ");
            }
        }
        fprintf(file, "\n");
    }
}
