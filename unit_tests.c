#include "unit_tests.h"
#include "io.h"
#include "processing.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

#define LINE_SIZE 100
#define MAX_NUMBERS 10000


int run_unit_tests() {
    
    FILE *file = fopen("tests/unit_test_input.txt", "r");
    if (!file) {
        printf("Ошибка открытия файла unit_test_input.txt\n");
        return 1;
    }
    int numbers[MAX_NUMBERS];
    int num_count = 0;
    assert(read_line(file, numbers, &num_count, MAX_NUMBERS) == 1);
    assert(num_count == 4);
    assert(numbers[0] == 7);
    assert(numbers[1] == 14);
    assert(numbers[2] == 27);
    assert(numbers[3] == 5);
    fclose(file);

    
    int input_numbers[] = {7, 14, 27, 5, 17, 37};
    int num_count2 = 6;
    int output[MAX_NUMBERS];
    int output_count = 0;
    extract_numbers_ends_7(input_numbers, num_count2, output, &output_count);
//    for(int i = 0; i < output_count; i++) printf("%d ", output[i]);
    assert(output_count == 4);
    assert(output[0] == 7);
    assert(output[1] == 27);
    assert(output[2] == 17);
    assert(output[3] == 37);

    
    int numbers2[] = {7, 14, 17, 5, 37, 27};
    int num_count3 = 6;
    asc_sort(numbers2, num_count3);
    assert(numbers2[0] == 5);
    assert(numbers2[1] == 7);
    assert(numbers2[2] == 14);
    assert(numbers2[3] == 17);
    assert(numbers2[4] == 27);
    assert(numbers2[5] == 37);

    
    int numbers3[] = {7, 14, 27, 5, 17, 37};
    int sorted_numbers[] = {17, 27, 37, 7};
    int sorted_count = 4;
    replace_sorted_numbers(numbers3, 6, sorted_numbers, sorted_count);
    assert(numbers3[0] == 17);
    assert(numbers3[1] == 14);
    assert(numbers3[2] == 27);
    assert(numbers3[3] == 5);
    assert(numbers3[4] == 37);
    assert(numbers3[5] == 7);

    
    FILE *output_file = fopen("tests/unit_test_output.txt", "w+");
    int numbers4[] = {7, 14, 27, 5};
    write_line(output_file, numbers4, 4);
    rewind(output_file);
    char buffer[LINE_SIZE];
    fgets(buffer, LINE_SIZE, output_file);
    assert(strcmp(buffer, "7 14 27 5\n") == 0);
    fclose(output_file);


    // printf("Unit tests passed!\n");
    return 0;
}
