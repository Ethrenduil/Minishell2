/*
** EPITECH PROJECT, 2020
** my_showstr.c
** File description:
** quentin.vandersteene@epitech.eu
*/

#include "../../includes/my.h"

void show_string(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return;
}