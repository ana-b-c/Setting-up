/*
** EPITECH PROJECT, 2024
** utils.c
** File description:
** utils
*/
#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void error_exit(const char *msg)
{
    my_putstr(msg);
    write(2, "\n", 1);
    exit(84);
}

static void grow_buffer_if_needed(char **line,
    int *buffer_size, int current_length)
{
    char *new_line;
    int j;

    if (current_length >= *buffer_size) {
        *buffer_size *= 2;
        new_line = malloc(*buffer_size);
        if (new_line == NULL) {
            free(*line);
            error_exit("Memory reallocation failed");
        }
        for (j = 0; j < current_length; j++) {
            new_line[j] = (*line)[j];
        }
        free(*line);
        *line = new_line;
    }
}

int read_line(int fd, char **line)
{
    int buffer_size = 128;
    char buf[1];
    int i = 0;

    *line = malloc(buffer_size);
    if (*line == NULL) {
        error_exit("Memory allocation failed");
    }
    while (read(fd, buf, 1) > 0) {
        if (buf[0] == '\n') {
            break;
        }
        (*line)[i] = buf[0];
        i++;
        grow_buffer_if_needed(line, &buffer_size, i);
    }
    (*line)[i] = '\0';
    return i;
}

void mark_largest_square(t_board *board, t_square *largest_square)
{
    int i;
    int j;

    if (largest_square->size <= 0) {
        return;
    }
    for (i = largest_square->x;
        i > largest_square->x - largest_square->size; i--) {
        for (j = largest_square->y;
            j > largest_square->y - largest_square->size; j--) {
                board->data[i][j] = 'x';
        }
    }
}

void free_dp(int **dp, int height)
{
    for (int i = 0; i < height; i++) {
        free(dp[i]);
    }
    free(dp);
}

void update_largest_square(int dp_value, int row, int col,
    t_square *largest_square)
{
    if (dp_value > largest_square->size) {
        largest_square->size = dp_value;
        largest_square->x = row;
        largest_square->y = col;
    }
}
