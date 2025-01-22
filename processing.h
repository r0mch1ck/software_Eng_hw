#ifndef PROCESSING_H
#define PROCESSING_H

#include "error_codes.h"

ErrorCode extract_numbers_ends_7(const int *numbers, int num_count, int *output, int *output_count);
ErrorCode asc_sort(int *arr, int size);
ErrorCode replace_sorted_numbers(int *numbers, int num_count, const int *sorted_numbers, int sorted_count);

#endif // PROCESSING_H
