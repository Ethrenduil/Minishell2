/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-quentin.vandersteene
** File description:
** my_cd
*/

#include "../includes/my.h"

void go_env(shell_t *shell, char *str)
{
    char *path = get_env_var(shell, str);
    if (chdir(path) == 0) {
        replace_oldpwd(shell);
        replace_pwd(shell);
    }
    else
        show_string(": No such file or directory.\n");
}

int check_cd_error(shell_t *shell, char *path)
{
    struct stat sb;

    stat(path, &sb);
    if (access(path, R_OK) == -1){
        show_string(path);
        return show_error(": No such file or directory.");
    }
    if (S_ISDIR(sb.st_mode) != 1 && access(path, R_OK) == 0) {
        show_string(path);
        return show_error(": Not a directory.");
    }
    if (S_ISDIR(sb.st_mode) == 1 && access(path, R_OK) != 0){
        show_string(path);
        return show_error(": Permission denied.");
    }
    return 0;
}

void my_cd2(shell_t *shell)
{
    if (check_cd_error(shell, shell->command[1]) == 84)
        return;
    if (chdir(shell->command[1]) == 0) {
        replace_oldpwd(shell);
        replace_pwd(shell);
    }
}

void my_cd3(shell_t *shell)
{
    if (my_strlen(shell->command[1]) == 1)
        go_env(shell, "OLDPWD");
    else
        show_string("Usage: cd [-plvn][-|<dir>].");
}

void my_cd(shell_t *shell)
{
    if (shell->nb > 1)
        show_string("cd: Too many arguments.\n");
    else {
        if (shell->nb == 0 || shell->command[1][0] == '~') {
            go_env(shell, "HOME");
        }
        else if (shell->command[1][0] == '-') {
            my_cd3(shell);
        }
        else
            my_cd2(shell);
    }
}