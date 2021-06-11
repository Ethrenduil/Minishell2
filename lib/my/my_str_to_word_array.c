/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-quentin.vandersteene
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

int nb_cols(char *str, char c)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != c)
        i++;
    return (i);
}

int nb_word(char *str, char c)
{
    int i = 0;
    int count = 1;

    while (str[i] != '\0') {
        if (str[i] == c)
            count++;
        i++;
    }
    return (count);
}

char **my_str_to_word_array(char *str, char c)
{
    int j = 0, k = 0;
    char **dest = malloc(sizeof(char *) * (nb_word(str, c) + 1));

    dest[j] = malloc(sizeof(char) * (nb_cols(str, c) + 1));
    while (str[0] != '\0') {
        if (str[0] == c || str[0] == '\t') {
            dest[j++][k] = '\0';
            k = 0;
            while (str[0] == c || str[0] == '\t')
                str++;
            dest[j] = malloc(sizeof(char) * (nb_cols(str, c) + 1));
        }
        if (str[0] != '\0' && str[0] != c)
            dest[j][k++] = str[0];
        str++;
    }
    dest[j][k] = '\0';
    dest[j + 1] = NULL;
    return (dest);
}