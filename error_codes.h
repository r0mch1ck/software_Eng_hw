//
// Created by Roman Kovalev on 22.01.2025.
//

#ifndef SOFTWARE_ING_ERROR_CODES_H
#define SOFTWARE_ING_ERROR_CODES_H

#ifndef ERROR_CODES_H
#define ERROR_CODES_H

typedef enum {
    SUCCESS = 0,
    ERROR_NULL_POINTER = 1,
    ERROR_FILE_READ = 2,
    ERROR_INVALID_INPUT = 3,
    ERROR_OUT_OF_RANGE = 4,
    ERROR_TOO_MANY_NUMBERS = 5,
    ERROR_SIZE = 6,
    ERROR_INVALID_COUNT = 7
} ErrorCode;

#endif // ERROR_CODES_H


#endif //SOFTWARE_ING_ERROR_CODES_H
