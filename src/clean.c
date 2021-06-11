/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-quentin.vandersteene
** File description:
** clean
*/

#include "../includes/my.h"

char *remove_space(char *str)
{
    int i = 0;

    for (; str[0] != '\0' && str[0] == ' '; str++);
    if (str[0] == '\0')
        return (str);
    for (; str[i + 1] != '\0'; i++);
    while (str[i] == ' ')
        i--;
    str[i + 1] = '\0';
    return (str);
}

char *remove_tab(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\t')
            str[i] = ' ';
        i++;
    }
    return (str);
}

char *clean_input(char *str)
{
    int i = 0;
    int j = 0;
    int count = 0;
    char *dest = NULL;

    str = remove_tab(str);
    dest = malloc(sizeof(char) * (my_strlen(str) + 1));
    while (str[i] != '\0') {
        if (str[i] == ' ')
            count++;
        else
            count = 0;
        if (count < 2)
            dest[j++] = str[i];
        i++;
    }
    dest[j] = '\0';
    dest = remove_space(dest);
    return dest;
}

void clean_all(shell_t *shell)
{
    for (int i = 0; shell->command[i] != NULL; i++)
        shell->command[i] = clean_input(shell->command[i]);
}