#include "processing.h"
#include <stdlib.h>

void extract_numbers_ends_7(const int *numbers, int num_count, int *output, int *output_count) {
    *output_count = 0;
    for (int i = 0; i < num_count; i++) {
        if (abs(numbers[i]) % 10 == 7) {
            output[(*output_count)++] = numbers[i];
        }
    }
}

void asc_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void replace_sorted_numbers(int *numbers, int num_count, const int *sorted_numbers, int sorted_count) {
    int sorted_index = 0;
    for (int i = 0; i < num_count; i++) {
        if (abs(numbers[i]) % 10 == 7 && sorted_index < sorted_count) {
            numbers[i] = sorted_numbers[sorted_index++];
        }
    }
}




