/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-quentin.vandersteene
** File description:
** pasing
*/

#include "../includes/my.h"

char *remove_enter(char *command)
{
    int i = 0;
    int a = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen(command) + 1));

    if (my_strlen(command) == 1)
        return command;
    while (command[i] == '\n' || command[i] == ' ' ||
    command[i] == '\t')
        i++;
    for (; command[i] != '\n' && command[i] != '\0'; i++, a++)
        tmp[a] = command[i];
    tmp[a] = '\0';
    for (a = my_strlen(tmp) - 1; tmp[a] == ' '; a--);
    a++;
    tmp[a] = '\0';
    free(command);
    return tmp;
}

int is_empty(char *str)
{
    if (my_strlen(str) == 0)
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t' &&
        str[i] != '\n')
            return 0;
    }
    return 1;
}

void parse(shell_t *shell)
{
    int i = 0;

    if (check_separator(shell) > 0)
        return;
    if (check_pipe(shell, shell->buff) > 0)
        return;
    if (check_redirection(shell) > 0)
        return;
    execute(shell, shell->buff);
}