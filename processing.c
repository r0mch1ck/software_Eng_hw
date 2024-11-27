#include "processing.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

void extract_numbers_and_spaces(const char *line, int *numbers, int *spaces, int *num_count, int *space_count) {
    int temp_space = 0;
    char temp[32];
    int temp_pos = 0;
    *num_count = 0;
    *space_count = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (isdigit(line[i])) {
            temp[temp_pos++] = line[i];
        } else {
            if (temp_pos > 0) {
                temp[temp_pos] = '\0';
                numbers[(*num_count)++] = atoi(temp);
                temp_pos = 0;
                if (temp_space > 0) {
                    spaces[(*space_count)++] = temp_space;
                    temp_space = 0;
                }
            }
            if (line[i] == ' ') {
                temp_space++;
            }
        }
    }

    if (temp_pos > 0) {
        temp[temp_pos] = '\0';
        numbers[(*num_count)++] = atoi(temp);
    }

    if (temp_space > 0) {
        spaces[(*space_count)++] = temp_space;
    }

    while (*space_count < *num_count - 1) {
        spaces[(*space_count)++] = 0;
    }
//    for (int i = 0; i < *num_count; i++) {
//        printf("%d ", numbers[i]);
//    }
//    printf("\n");
//    for (int i = 0; i < *num_count; i++) {
//        printf("%d ", spaces[i]);
//    }
//    printf("\n");
}

void sort_numbers_ends_7(int *numbers, int count) {
    int indices[count];
    int indices_count = 0;

    for (int i = 0; i < count; i++) {
        if (numbers[i] % 10 == 7) {
            indices[indices_count++] = i;
        }
    }

    for (int i = 0; i < indices_count - 1; i++) {
        for (int j = i + 1; j < indices_count; j++) {
            if (numbers[indices[i]] > numbers[indices[j]]) {
                int temp = numbers[indices[i]];
                numbers[indices[i]] = numbers[indices[j]];
                numbers[indices[j]] = temp;
            }
        }
    }
}

void combine_spaces_with_numbers(const int *numbers, const int *spaces, int num_count, int space_count, char *result) {
    char buffer[32];
    int pos = 0;

    for (int i = 0; i < num_count; i++) {
        sprintf(buffer, "%d", numbers[i]);
        for (int j = 0; buffer[j] != '\0'; j++) {
            result[pos++] = buffer[j];
        }

        if (i < space_count) {
            for (int j = 0; j < spaces[i]; j++) {
                result[pos++] = ' ';
            }
        }
    }
    result[pos] = '\0';
}
