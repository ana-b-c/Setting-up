/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/
#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
    t_board board;

    if (argc < 2 || argc > 3) {
        error_exit("Incorrect usage of ./setting_up");
    }
    if (argc == 2) {
        check_file_exists(argv[1]);
        board = read_board_from_file(argv[1]);
    } else if (argc == 3) {
        generate_board_from_params(&board, argv[1], argv[2]);
    }
    find_largest_square(&board);
    free_board(&board);
    return 0;
}

void generate_board_from_params(t_board *board, char *width_str, char *pattern)
{
    int pattern_len;
    int continuous_index;

    board->width = my_getnbr(width_str);
    board->height = my_getnbr(width_str);
    if (my_strlen(pattern) == 0) {
        error_exit("No pattern found");
    }
    board->data = safe_malloc(sizeof(char *) * board->height);
    for (int i = 0; i < board->height; i++) {
        pattern_len = my_strlen(pattern);
        board->data[i] = safe_malloc(sizeof(char) * (board->width + 1));
        for (int j = 0; j < board->width; j++) {
            continuous_index = (i * board->width + j) % pattern_len;
            board->data[i][j] = pattern[continuous_index];
        }
        board->data[i][board->width] = '\0';
    }
}
