#include <stdio.h>
#include "io.h"
#include "processing.h"
#include "unit_tests.h"

#define LINE_SIZE 100000
#define MAX_NUMBERS 10000

int main(int argc, char *argv[]) {
//    if (run_unit_tests() != 0) {
//        printf("Unit test failed");
//        return 1;
//    }

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 0;
    }

    FILE *input_file = open_file(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Failed to open input file.\n");
        return 1;
    }

    FILE *output_file = open_file(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Failed to open output file.\n");
        fclose(input_file);
        return 1;
    }

    int numbers[MAX_NUMBERS], temp_numbers[MAX_NUMBERS];
    int num_count, temp_count;

    ErrorCode error_code;

    while ((error_code = read_line(input_file, numbers, &num_count, MAX_NUMBERS)) == SUCCESS) {
        if (num_count == 0) {
            if ((error_code = write_line(output_file, numbers, 0)) != SUCCESS) {
                fprintf(stderr, "Error: Failed to write empty line to output file.\n");
                fclose(input_file);
                fclose(output_file);
                return 1;
            }
            continue;
        }

        if ((error_code = extract_numbers_ends_7(numbers, num_count, temp_numbers, &temp_count)) != SUCCESS) {
            fprintf(stderr, "Error: Failed to extract numbers ending with 7.\n");
            fclose(input_file);
            fclose(output_file);
            return 1;
        }

        if ((error_code = asc_sort(temp_numbers, temp_count)) != SUCCESS) {
            fprintf(stderr, "Error: Failed to sort numbers.\n");
            fclose(input_file);
            fclose(output_file);
            return 1;
        }

        if ((error_code = replace_sorted_numbers(numbers, num_count, temp_numbers, temp_count)) != SUCCESS) {
            fprintf(stderr, "Error: Failed to replace sorted numbers.\n");
            fclose(input_file);
            fclose(output_file);
            return 1;
        }

        if ((error_code = write_line(output_file, numbers, num_count)) != SUCCESS) {
            fprintf(stderr, "Error: Failed to write line to output file.\n");
            fclose(input_file);
            fclose(output_file);
            return 1;
        }
    }

    if (error_code != SUCCESS && error_code != ERROR_FILE_READ) {
        fprintf(stderr, "Error: An error occurred while reading the input file.\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    fclose(input_file);
    fclose(output_file);

    printf("Processing completed. Results saved to file: %s\n", argv[2]);

    return 0;
}
