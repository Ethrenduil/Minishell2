/*
** EPITECH PROJECT, 2020
** reverse_string.c
** File description:
** retourner  la liste chainée
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

char *reverse_string(char *str)
{
    int i = my_strlen(str);
    int j = 0;
    char c;

    while (i > j) {
        i--;
        c = str[j];
        str[j] = str[i];
        str[i] = c;
        j++;
    }
    return str;
}