/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-quentin.vandersteene
** File description:
** check
*/

#include "../includes/my.h"

int check_redirection(shell_t *shell)
{
    int redi = 0;

    for (int i = 0; shell->buff[i] != '\0'; i++)
        if (shell->buff[i] == '>' || shell->buff[i] == '<')
            redi++;
    if (redi > 0);
    return redi;
}

int check_pipe(shell_t *shell, char *buff)
{
    int pipes = 0;

    for (int i = 0; buff[i] != '\0'; i++)
        if (buff[i] == '|')
            pipes++;
    if (pipes > 0)
        execute_pipe(shell, buff);
    return pipes;
}

int check_separator(shell_t *shell)
{
    int sepa = 0;

    for (int i = 0; shell->buff[i] != '\n'; i++) {
        if (shell->buff[i] == ';')
            sepa++;
    }
    if (sepa > 0)
        execute_separator(shell);
    return sepa;
}