/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-quentin.vandersteene
** File description:
** main
*/

#include "../includes/my.h"

void get_pwd(shell_t *shell)
{
    long int size = 1000;
    char *pwd = get_env_var(shell, "PWD");
    show_string(pwd);
}

int get_buff(shell_t *shell)
{
    long int size = 1000;

    shell->buff = malloc(sizeof(char) * size);
    if (shell->buff == NULL)
        exit(show_error(MALLOC));
    if (getline(&shell->buff, &size, stdin) == -1) {
        show_string("exit\n");
        exit(0);
    }
    clean_input(shell->buff);
}

int main(int nb, char **arg, char **env)
{
    shell_t *shell = malloc(sizeof(shell_t));

    shell->env = env;
    replace_pwd(shell);
    if (shell == NULL)
        exit(show_error(MALLOC));
    while (1) {
        signal(SIGTSTP, SIG_IGN);
        signal(SIGINT, SIG_IGN);
        get_pwd(shell);
        show_string("> ");
        get_buff(shell);
        parse(shell);
    }
    return 0;
}