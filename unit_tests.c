#include "unit_tests.h"
#include "io.h"
#include "processing.h"
#include "error_codes.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

#define LINE_SIZE 100
#define MAX_NUMBERS 10000

int run_unit_tests() {
    // Test A1: read_line
    FILE *file = fopen("../unit_tests/readLineBase.txt", "r");
    if (!file) {
        printf("Error opening file readLineBase.txt\n");
        return 1;
    }
    int numbers[MAX_NUMBERS];
    int num_count = 0;

    // A1.1 Check successful reading of a line
    assert(read_line(file, numbers, &num_count, MAX_NUMBERS) == SUCCESS);
    assert(num_count == 4);
    assert(numbers[0] == 7);
    assert(numbers[1] == 14);
    assert(numbers[2] == 27);
    assert(numbers[3] == 5);

    // A1.2 Check reading a line with INT_MAX and INT_MIN
    FILE *file2 = fopen("../unit_tests/boundary_values.txt", "r");
    assert(file2 != NULL);
    assert(read_line(file2, numbers, &num_count, MAX_NUMBERS) == SUCCESS);
    assert(num_count == 2);
    assert(numbers[0] == 2147483647);  // INT_MAX
    assert(numbers[1] == -2147483648); // INT_MIN
    fclose(file2);

    // A1.3 Check a line with 10,001 numbers (overflow test)
    FILE *file3 = fopen("../unit_tests/overflow_test.txt", "r");
    assert(file3 != NULL);
    assert(read_line(file3, numbers, &num_count, MAX_NUMBERS) == ERROR_TOO_MANY_NUMBERS);  // Overflow limit
    fclose(file3);

    fclose(file);

    // Test A2: extract_numbers_ends_7
    int input_numbers[] = {7, 14, 27, 5, 17, 37, 2147483647, -2147483648};
    int num_count2 = 8;
    int output[MAX_NUMBERS];
    int output_count = 0;

    // A2.1 Extract numbers ending with 7
    assert(extract_numbers_ends_7(input_numbers, num_count2, output, &output_count) == SUCCESS);
    assert(output_count == 5);
    assert(output[0] == 7);
    assert(output[1] == 27);
    assert(output[2] == 17);
    assert(output[3] == 37);

    // A2.2 No numbers ending with 7
    int input_numbers2[] = {10, 20, 30};
    int num_count3 = 3;
    output_count = 0;
    assert(extract_numbers_ends_7(input_numbers2, num_count3, output, &output_count) == SUCCESS);
    assert(output_count == 0);

    // A2.3 All numbers end with 7
    int input_numbers3[] = {7, 17, 27};
    int num_count4 = 3;
    output_count = 0;
    assert(extract_numbers_ends_7(input_numbers3, num_count4, output, &output_count) == SUCCESS);
    assert(output_count == 3);
    assert(output[0] == 7);
    assert(output[1] == 17);
    assert(output[2] == 27);

    // Test A3: asc_sort
    int numbers2[] = {2147483647, -2147483648, 7, 14};
    int num_count5 = 4;

    // A3.1 Sorting in ascending order
    assert(asc_sort(numbers2, num_count5) == SUCCESS);
    assert(numbers2[0] == -2147483648);
    assert(numbers2[1] == 7);
    assert(numbers2[2] == 14);
    assert(numbers2[3] == 2147483647);

    // A3.2 Sorting an already sorted array
    int numbers3[] = {5, 7, 14, 17};
    int num_count6 = 4;
    assert(asc_sort(numbers3, num_count6) == SUCCESS);
    assert(numbers3[0] == 5);
    assert(numbers3[1] == 7);
    assert(numbers3[2] == 14);
    assert(numbers3[3] == 17);

    // Test A4: replace_sorted_numbers
    int numbers4[] = {7, 14, 27, 5, 17, 37};
    int sorted_numbers[] = {17, 27, 37, 7};
    int sorted_count = 4;

    // A4.1 Replacing numbers ending with 7
    assert(replace_sorted_numbers(numbers4, 6, sorted_numbers, sorted_count) == SUCCESS);
    assert(numbers4[0] == 17);
    assert(numbers4[1] == 14);
    assert(numbers4[2] == 27);
    assert(numbers4[3] == 5);
    assert(numbers4[4] == 37);
    assert(numbers4[5] == 7);

    // A4.2 Partial replacement
    int numbers5[] = {7, 14, 17};
    int sorted_numbers2[] = {27};
    assert(replace_sorted_numbers(numbers5, 3, sorted_numbers2, 1) == SUCCESS);
    assert(numbers5[0] == 27);
    assert(numbers5[1] == 14);
    assert(numbers5[2] == 17);

    // A4.3 No numbers to replace
    int numbers6[] = {10, 20, 30};
    int sorted_numbers3[] = {7};
    assert(replace_sorted_numbers(numbers6, 3, sorted_numbers3, 1) == SUCCESS);
    assert(numbers6[0] == 10);
    assert(numbers6[1] == 20);
    assert(numbers6[2] == 30);

    // Test A5: write_line
    FILE *output_file = fopen("../unit_tests/writeLineBase.txt", "w+");
    int numbers7[] = {7, 14, 27, 5};
    assert(write_line(output_file, numbers7, 4) == SUCCESS);
    rewind(output_file);
    char buffer[LINE_SIZE];
    fgets(buffer, LINE_SIZE, output_file);
    assert(strcmp(buffer, "7 14 27 5\n") == 0);
    fclose(output_file);

    // A5.1 Test writing with INT_MAX and INT_MIN
    FILE *output_file2 = fopen("../unit_tests/boundary_output.txt", "w+");
    int numbers8[] = {2147483647, -2147483648, 0};
    assert(write_line(output_file2, numbers8, 3) == SUCCESS);
    rewind(output_file2);
    fgets(buffer, LINE_SIZE, output_file2);
    assert(strcmp(buffer, "2147483647 -2147483648 0\n") == 0);
    fclose(output_file2);

    // Output message about successfully passing the tests
    printf("All unit tests passed successfully.\n");
    return 0;
}
