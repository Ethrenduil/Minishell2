/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** quentin.vandersteene@epitech.eu
*/

#include "../../includes/my.h"

int sign_check(char *str)
{
    int i = 1;
    int j = 0;

    while (str[j] == '-' || str[j] == '+') {
        if (str[j] == '-') {
            i *= -1;
            j++;
        }
        else
            j++;
    }
    return i;
}

int is_number(char c)
{
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

int is_signe(char c)
{
    if (c == '+' && c == '-') {
        return 1;
    }
    return 0;
}

int char_number(char *nb)
{
    int i = 0;
    while (nb[i] != '\0') {
        if (is_number(nb[i]) == 0)
            return 0;
        else
            i++;
    }
    return 1;
}

int my_to_number(char *str)
{
    int chiffre = 0;
    int i = 0;

    while (is_number(str[i]) == 0) {
        if (is_signe(str[i]) == 0)
            return 0;
        else
            i++;
    }
    while (is_number(str[i]) == 1) {
        chiffre *= 10;
        chiffre += (str[i] - '0');
        i++;
    }
    if (sign_check(str) == -1)
        chiffre *= -1;
    return chiffre;
}