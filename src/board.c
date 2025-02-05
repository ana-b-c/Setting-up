/*
** EPITECH PROJECT, 2024
** board
** File description:
** board
*/
#include "my.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

t_board read_board_from_file(char *filename)
{
    t_board board;
    int fd = open(filename, O_RDONLY);
    char *line = NULL;

    board.height = 0;
    if (fd == -1) {
        error_exit("Failed to open file");
    }
    board.height = read_and_get_board_height(fd, &line);
    board.data = allocate_board_data(board.height);
    read_board_data(fd, &board);
    if (board.width <= 0) {
        close(fd);
        error_exit("Invalid width in map file");
    }
    close(fd);
    return board;
}

int read_and_get_board_height(int fd, char **line)
{
    int height;

    read_line(fd, line);
    height = my_getnbr(*line);
    free(*line);
    return height;
}

char **allocate_board_data(int height)
{
    char **data = safe_malloc(sizeof(char *) * height);

    return data;
}

void read_board_data(int fd, t_board *board)
{
    char *line = NULL;
    int len;

    for (int i = 0; i < board->height; i++) {
        len = read_line(fd, &line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }
        if (i == 0) {
            board->width = len;
        } else {
            validate_row_length(len, board->width, i + 1);
        }
        validate_row_characters(line, len, i + 1);
        board->data[i] = safe_malloc(sizeof(char) * (len + 1));
        my_strcpy(board->data[i], line);
        free(line);
    }
}

void print_board(t_board *board)
{
    for (int i = 0; i < board->height; i++) {
        write(1, board->data[i], my_strlen(board->data[i]));
        write(1, "\n", 1);
    }
}
