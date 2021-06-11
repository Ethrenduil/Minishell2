/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-quentin.vandersteene
** File description:
** env2
*/

#include "../includes/my.h"

void remove_var(shell_t *shell, int line)
{
    int lines = 0, i = 0, j = 0;
    char **env, *new = NULL;

    for (i = 0; shell->env[i] != NULL; i++, lines++);
    env = malloc(sizeof(char *) * (lines + 3));
    for (i = 0; shell->env[j] != NULL; i++, j++) {
        env[i] = malloc(sizeof(char) * (my_strlen(shell->env[i]) + 2));
        if (i == line)
            j++;
        env[i] = shell->env[j];
    }
    env[i] = NULL;
    env[i + 1] = NULL;
    shell->env = env;
}

void my_unsetenv2(shell_t *shell, char *command)
{
    int same = 0;

    for (int i = 0; shell->env[i] != NULL; i++, same = 0) {
        for (int j = 0; shell->env[i][j] != '=' &&
        shell->env[i][j] != '\0' && command[j] != '\0'; j++) {
            if (shell->env[i][j] == command[j])
                same++;
        }
        if (same == my_strlen(command))
            remove_var(shell, i);
    }
}

void my_unsetenv(shell_t *shell)
{
    if (shell->nb < 1) {
        show_string("unsetenv: Too few arguments.\n");
        return;
    }
    
    for (int i = 1; shell->command[i] != NULL; i++)
        my_unsetenv2(shell, shell->command[i]);
}