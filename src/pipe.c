/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-quentin.vandersteene
** File description:
** pipe
*/

#include "../includes/my.h"

void first_pipe(shell_t *shell, char *command, pipe_t *pipes,char **env)
{
    pid_t pid = 0;

    if ((pid = fork()) == 0) {
        dup2(pipes->fd[1], 1);
        close(pipes->fd[0]);
        execute(shell, command);
        exit(1);
    } else {
        close(pipes->fd[1]);
        pipes->save = pipes->fd[0];
    }
    pipes->pid = go_tab(pipes->pid, pid, pipes->max_len);
}

void multi_pipe(shell_t *shell, char *command, pipe_t *pipes,char **env)
{
    pid_t pid = 0;

    if ((pid = fork()) == 0) {
        dup2(pipes->save, 0);
        dup2(pipes->fd[1], 1);
        close(pipes->fd[0]);
        execute(shell, command);
        exit(1);
    } else {
        close(pipes->fd[1]);
        close(pipes->save);
        pipes->save = pipes->fd[0];
    }
    pipes->pid = go_tab(pipes->pid, pid, pipes->max_len);
}

void last_pipe(shell_t *shell, char *command, pipe_t *pipes,char **env)
{
    pid_t pid = 0;

    if ((pid = fork()) == 0) {
        dup2(pipes->fd[0], 0);
        close(pipes->save);
        close(pipes->fd[1]);
        execute(shell, command);
        exit(1);
    } else {
        close(pipes->fd[0]);
        close(pipes->fd[1]);
        close(pipes->save);
    }
    pipes->pid = go_tab(pipes->pid, pid, pipes->max_len);
}

int check_pipe_error(char *command)
{
    for (int i = 0; command[i] != '\0'; i++)
        if (command[i] == '|' && command[i + 1] == '\0')
            return show_error("Invalid null command.");
    return 0;
}

void execute_pipe2(shell_t *shell, char *command, int i, pipe_t *pipes)
{
    int max = nb_lines(shell->command) - 1;

    if (i < max)
        pipe(pipes->fd);
    if (i == max)
        last_pipe(shell, command, pipes, shell->env);
    else if (i == 0)
        first_pipe(shell, command, pipes, shell->env);
    else
        multi_pipe(shell, command, pipes, shell->env);
}