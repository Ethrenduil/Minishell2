/*
** EPITECH PROJECT, 2020
** show_params.c
** File description:
** affiche params
*/

#include "../../includes/my.h"

void show_params(int nb, char **arg)
{
    for (int i = 0; i < nb; i++) {
        show_string(arg[i]);
        my_putchar('\n');
    }
    return;
}