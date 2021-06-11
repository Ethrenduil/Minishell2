/*
** EPITECH PROJECT, 2020
** is_alphanum.c
** File description:
** is_alphanum
*/

int is_alphanum(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
    || (c >= 'a' && c <= 'z')) {
        return (1);
    }
    return (0);
}

int is_alpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return (1);
    }
    return (0);
}