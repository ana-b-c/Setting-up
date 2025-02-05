/{*
** EPITECH PROJECT, 2024
** my.c
** File description:
** lib
*/
#include "my.h"
#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
    my_putchar('-');
    nb = -nb;
    }
    if (nb == 0) {
    my_putchar('0');
    return 0;
    }
    if (nb / 10 != 0) {
    my_put_nbr(nb / 10);
    }
    my_putchar((nb % 10) + '0');
    return 0;
}

int my_strlen(char const *str)
{
    int length = 0;

    while (str[length] != '\0') {
    length++;
    }
    return length;
}

static int extract_number(const char *str, int *i, int is_neg)
{
    long number = 0;

    while (str[*i] >= '0' && str[*i] <= '9') {
        number = number * 10 + (str[*i] - '0');
        (*i)++;
        if (number > 2147483647) {
            return 0;
        }
    }
    return (int)(number * is_neg);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int is_neg = 1;
    int action;

    while (str[i] != '\0') {
        action = (str[i] == '-') * -1 + (str[i] >= '0' && str[i] <= '9');
        is_neg *= (action == -1) ? -1 : 1;
        if (action == 1) {
            return extract_number(str, &i, is_neg);
        }
        i++;
    }
    return 0;
}

void free_board(t_board *board)
{
    for (int i = 0; i < board->height; i++) {
        free(board->data[i]);
    }
    free(board->data);
}
