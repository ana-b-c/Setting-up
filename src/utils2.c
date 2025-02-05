/*
** EPITECH PROJECT, 2024
** utils2.c
** File description:
** 2
*/
#include "my.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

void check_file_exists(const char *filename)
{
    struct stat buffer;

    if (stat(filename, &buffer) != 0) {
        error_exit("File does not exist or cannot be accessed");
    }
}

void *safe_malloc(int size)
{
    void *ptr = malloc(size);

    if (!ptr) {
        error_exit("Memory allocation failed");
    }
    return ptr;
}

void validate_row_length(int current_length, int expected_length,
    int line_number)
{
    if (current_length != expected_length) {
        error_exit("Invalid row length on line");
    }
}

void validate_row_characters(const char *row, int row_length, int line_number)
{
    for (int i = 0; i < row_length; i++) {
        if (row[i] != '.' && row[i] != 'o') {
            error_exit("Invalid character in map file");
        }
    }
}
