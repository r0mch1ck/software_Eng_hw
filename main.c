#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"
#include "processing.h"

#define LINE_SIZE 1024
#define MAX_NUMBERS 10000

int main() {
    char input_filename[256];
    char output_filename[256];

    printf("Enter the name of the input file: ");
    if (scanf("%255s", input_filename) != 1) {
        fprintf(stderr, "Error reading the input file name.\n");
        return 1;
    }

    printf("Enter the name of the output file: ");
    if (scanf("%255s", output_filename) != 1) {
        fprintf(stderr, "Error reading the output file name.\n");
        return 1;
    }

    FILE *input_file = fopen(input_filename, "r");
    if (!input_file) {
        fprintf(stderr, "Error opening the input file.\n");
        return 1;
    }

    FILE *output_file = fopen(output_filename, "w");
    if (!output_file) {
        fprintf(stderr, "Error opening the output file.\n");
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

    printf("Processing completed. Results saved to file %s\n", output_filename);

    return 0;
}
