#ifndef PROCESSING_H
#define PROCESSING_H

void extract_numbers_ends_7(const int *numbers, int num_count, int *output, int *output_count);
void asc_sort(int *arr, int size);
void replace_sorted_numbers(int *numbers, int num_count, const int *sorted_numbers, int sorted_count);
int parse_numbers(const char *line, int *numbers);

#endif // PROCESSING_H
