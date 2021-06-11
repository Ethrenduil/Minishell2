/*
** EPITECH PROJECT, 2020
** my_showstr.c
** File description:
** quentin.vandersteene@epitech.eu
*/

#include "../../includes/my.h"

int show_error(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_puterror(str[i]);
    my_puterror('\n');
    return (84);
}
