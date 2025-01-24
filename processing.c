#include "processing.h"
#include <stdlib.h>

ErrorCode extract_numbers_ends_7(const int *numbers, int num_count, int *output, int *output_count) {
    if (numbers == NULL || output == NULL || output_count == NULL) {
        return ERROR_NULL_POINTER;
    }

    *output_count = 0;
    for (int i = 0; i < num_count; i++) {
        if (abs(numbers[i]) % 10 == 7) {
            output[(*output_count)++] = numbers[i];
        }
    }

    return SUCCESS;
}

ErrorCode asc_sort(int *arr, int size) {
    if (arr == NULL) {
        return ERROR_NULL_POINTER;
    }

    if (size <= 0) {
        return ERROR_SIZE;
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return SUCCESS;
}

ErrorCode replace_sorted_numbers(int *numbers, int num_count, const int *sorted_numbers, int sorted_count) {
    if (numbers == NULL || sorted_numbers == NULL) {
        return ERROR_NULL_POINTER;
    }

    int sorted_index = 0;
    for (int i = 0; i < num_count; i++) {
        if (abs(numbers[i]) % 10 == 7 && sorted_index < sorted_count) {
            numbers[i] = sorted_numbers[sorted_index++];
        }
    }

    return SUCCESS;
}
