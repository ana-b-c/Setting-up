/*
** EPITECH PROJECT, 2024
** find_square.c
** File description:
** find_square
*/
#include "my.h"
#include <stdlib.h>
#include <unistd.h>

void find_largest_square(t_board *board)
{
    int **dp;
    t_square largest_square;

    if (board->height <= 0 || board->width <= 0) {
        write(1, "Invalid board dimensions\n", 25);
        return;
    }
    dp = initialize_dp(board->height, board->width);
    largest_square = find_square_details(board, dp);
    mark_largest_square(board, &largest_square);
    print_board(board);
    free_dp(dp, board->height);
}

int **initialize_dp(int height, int width)
{
    int **dp = safe_malloc(sizeof(int *) * height);

    for (int i = 0; i < height; i++) {
        dp[i] = safe_malloc(sizeof(int) * width);
    }
    return dp;
}

t_square find_square_details(t_board *board, int **dp)
{
    int i;
    t_square largest_square = {0, 0, 0};

    for (i = 0; i < board->height; i++) {
        process_row(board, dp, i, &largest_square);
    }
    return largest_square;
}

void process_row(t_board *board, int **dp, int row, t_square *largest_square)
{
    int j;

    for (j = 0; j < board->width; j++) {
        dp[row][j] = compute_dp_value(board, dp, row, j);
        update_largest_square(dp[row][j], row, j, largest_square);
    }
}

int compute_dp_value(t_board *board, int **dp, int i, int j)
{
    int value = 0;

    if (board->data[i][j] == '.') {
        value = (i == 0 || j == 0) ? 1 : get_minimum(dp[i - 1][j - 1],
            dp[i - 1][j], dp[i][j - 1]) + 1;
    }
    return value;
}
