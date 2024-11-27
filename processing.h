#ifndef PROCESSING_H
#define PROCESSING_H

void extract_numbers_and_spaces(const char *line, int *numbers, int *spaces, int *num_count, int *space_count);
void sort_numbers_ends_7(int *numbers, int count);
void combine_spaces_with_numbers(const int *numbers, const int *spaces, int num_count, int space_count, char *result);

#endif // PROCESSING_H
