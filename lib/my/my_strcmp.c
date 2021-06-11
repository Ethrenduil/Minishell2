/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-quentin.vandersteene
** File description:
** my_strcmp
*/

#include <stdio.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int my_strcmp(char *a, char *b)
{
    int i = 0;
    int j = 0;

    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] == b[i])
            j++;
        i++;
    }
    if (a[i] != '\0' || (b[i] != '\n' && b[i] != '\0'))
        return 1;
    if (j != i)
        return i;
    return 0;
}