/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** lib
*/
#ifndef MY_H
    #define MY_H

typedef struct s_square {
    int x;
    int y;
    int size;
} t_square;

typedef struct s_board {
    char **data;
    int height;
    int width;
} t_board;

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
int get_minimum(int a, int b, int c);

t_board read_board_from_file(char *filename);
void generate_board_from_params(t_board *board,
    char *width_str, char *pattern);
void print_board(t_board *board);
void free_board(t_board *board);

void find_largest_square(t_board *board);

void error_exit(const char *msg);
int read_line(int fd, char **line);
void mark_largest_square(t_board *board, t_square *largest_square);
void free_dp(int **dp, int height);
void update_largest_square(int dp_value, int row, int col,
    t_square *largest_square);
int **initialize_dp(int height, int width);
t_square find_square_details(t_board *board, int **dp);
char **allocate_board_data(int height);
void *safe_malloc(int size);
void check_file_exists(const char *filename);
void validate_row_length(int current_length, int expected_length,
    int line_number);
void validate_row_characters(const char *row, int row_length, int line_number);

#endif
