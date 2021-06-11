/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-quentin.vandersteene
** File description:
** my_shell
*/

#include "../includes/my.h"

int *go_tab(int *tab, int elem, int max)
{
    int index = 0;

    if (index == max)
        return tab;
    tab[index++] = elem;
    return tab;
}

void replace_pwd(shell_t *shell)
{
    long int size = 1000;
    int same = 0;
    char *buff = malloc(sizeof(char) * (size + 1));
    if (buff == NULL)
        exit(show_error(MALLOC));
    char *old = "PWD";

    getcwd(buff, size);
    for (int i = 0; shell->env[i] != NULL; i++, same = 0) {
        for (int j = 0; shell->env[i][j] != '=' &&
        shell->env[i][j] != '\0' && old[j] != '\0'; j++) {
            if (shell->env[i][j] == old[j])
                same++;
        }
        if (same == my_strlen(old))
            return change_var(shell, i, old, buff);
    }
    add_var(shell, old, buff);
}

void replace_oldpwd(shell_t *shell)
{
    int same = 0;
    char *old = "OLDPWD\0";
    char *pwd = get_env_var(shell, "PWD");

    for (int i = 0; shell->env[i] != NULL; i++, same = 0) {
        for (int j = 0; shell->env[i][j] != '=' &&
        shell->env[i][j] != '\0' && old[j] != '\0'; j++) {
            if (shell->env[i][j] == old[j])
                same++;
        }
        if (same == my_strlen(old))
            return change_var(shell, i, old, pwd);
    }
    add_var(shell, old, pwd);
}

void my_exit(shell_t *shell)
{
    if (shell->nb == 0) {
        show_string("exit\n");
        exit(0);
    }
    else if (shell->nb == 1 && char_number(shell->command[1]) != 0) {
        show_string("exit\n");
        exit(my_to_number(shell->command[1]));
    }
    else
        show_string("exit: Expression Syntax.\n");
}

char *get_env_var(shell_t *shell, char *look)
{
    int same = 0;
    char *new;

    for (int i = 0; shell->env[i] != NULL; i++, same = 0) {
        for (int j = 0; shell->env[i][j] != '=' &&
        shell->env[i][j] != '\0'; j++) {
            if (shell->env[i][j] == look[j])
                same++;
        }
        if (same == my_strlen(look)) {
            new = shell->env[i];
            return new + my_strlen(look) + 1;
        }
    }
    return " ";
}