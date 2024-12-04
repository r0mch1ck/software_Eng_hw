#include <stdio.h>
#include "io.h"
#include "processing.h"
#include "unit_tests.h"

#define LINE_SIZE 100000
#define MAX_NUMBERS 10000

int main(int argc, char *argv[]) {
    if (run_unit_tests() != 0) {
        printf("Ошибка при выполнении юнит тестов.\n");
        return 1;
    }

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 0;
    }


    FILE *input_file = open_file(argv[1], "r");
    FILE *output_file = open_file(argv[2], "w");

    int numbers[MAX_NUMBERS], temp_numbers[MAX_NUMBERS];
    int num_count, temp_count;

    
    while (read_line(input_file, numbers, &num_count, MAX_NUMBERS)) {
        if (num_count == 0) {
            write_line(output_file, numbers, 0);  
            continue;  
        }

        extract_numbers_ends_7(numbers, num_count, temp_numbers, &temp_count);

        asc_sort(temp_numbers, temp_count);

        replace_sorted_numbers(numbers, num_count, temp_numbers, temp_count);

        write_line(output_file, numbers, num_count);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Processing completed. Results saved to file: %s\n", argv[2]);

    return 0;
}
