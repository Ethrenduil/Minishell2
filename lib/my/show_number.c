/*
** EPITECH PROJECT, 2020
** show_number.c
** File description:
** Affiche le nombre
*/

#include <stdlib.h>

void my_putchar(char c);

int show_number(int nb)
{
    int neg = 0;
    if (nb < 0) {
        neg = 1;
        nb++;
        my_putchar('-');
        nb = -nb;
    }

    if (nb>9) {
        show_number((nb - (nb%10)) / 10);
        if (neg == 1) {
            nb--;
        }
        my_putchar((nb % 10) + 48);
    }
    else {
        my_putchar(nb + 48);
    }
}