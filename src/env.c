/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-quentin.vandersteene
** File description:
** env
*/

#include "../includes/my.h"

void show_env(shell_t *shell)
{
    for (int i = 0; shell->env[i] != NULL; i++) {
        show_string(shell->env[i]);
        my_putchar('\n');
    }
}

void change_var(shell_t *shell, int line, char *name, char *value)
{
    shell->env[line] = my_strcat(name, "=");
    if (value != NULL)
        shell->env[line] = my_strcat(shell->env[line], value);
}

void add_var(shell_t *shell, char *var, char *content)
{
    int lines = 0, i = 0, j = 0;
    char **env, *new = NULL;

    for (i = 0; shell->env[i] != NULL; i++, lines++);
    env = malloc(sizeof(char *) * (lines + 3));
    for (i = 0; shell->env[i] != NULL; i++) {
        env[i] = malloc(sizeof(char) * (my_strlen(shell->env[i]) + 2));
        for (j = 0; shell->env[i][j] != '\0'; j++)
            env[i][j] = shell->env[i][j];
        env[i][j] = '\0';
    }
    new = my_strcat(var, "=");
    if (content != NULL)
        new = my_strcat(new, content);
    env[lines] = new;
    env [lines + 1] = NULL;
    env [lines + 2] = NULL;
    shell->env = env;
}

int setenv_error(shell_t *shell)
{
    if (shell->nb > 2) {
        show_string("setenv: Too many arguments.\n");
        return 1;
    }
    if (shell->nb == 0) {
        show_env(shell);
        return 1;
    }
    if (is_alpha(shell->command[1][0]) != 1) {
        show_string("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    for (int i = 0; i < my_strlen(shell->command[1]); i++) {
        if (is_alpha(shell->command[1][i]) != 1) {
            show_string("setenv: Variable name must"
            " contain alphanumeric characters.\n");
            return 1;
        }
    }
    return 0;
}

void my_setenv(shell_t *shell)
{
    int same = 0;

    if (setenv_error(shell) == 1)
        return;
    for (int i = 0; shell->env[i] != NULL; i++, same = 0) {
        for (int j = 0; shell->env[i][j] != '=' &&
        shell->env[i][j] != '\0' && shell->command[1][j] != '\0'; j++) {
            if (shell->env[i][j] == shell->command[1][j])
                same++;
        }
        if (same == my_strlen(shell->command[1]))
            return change_var(shell, i, shell->command[1], shell->command[2]);
    }
    add_var(shell, shell->command[1], shell->command[2]);
}