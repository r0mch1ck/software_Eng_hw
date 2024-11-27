#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"
#include "processing.h"

#define LINE_SIZE 1024
#define MAX_NUMBERS 10000

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        fprintf(stderr, "Error opening the input file: %s\n", argv[1]);
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (!output_file) {
        fprintf(stderr, "Error opening the output file: %s\n", argv[2]);
        fclose(input_file);
        return 1;
    }

    char line[LINE_SIZE];
    int numbers[MAX_NUMBERS], spaces[MAX_NUMBERS];
    int num_count, space_count;
    char result[LINE_SIZE];

    while (fgets(line, sizeof(line), input_file)) {
        line[strcspn(line, "\n")] = '\0';

        if (strlen(line) == 0) {
            continue;
        }

        extract_numbers_and_spaces(line, numbers, spaces, &num_count, &space_count);
        sort_numbers_ends_7(numbers, num_count);
        combine_spaces_with_numbers(numbers, spaces, num_count, space_count, result);
        write_line(output_file, result);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Processing completed. Results saved to file %s\n", argv[2]);

    return 0;
}
