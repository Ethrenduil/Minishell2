/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-quentin.vandersteene
** File description:
** execute
*/

#include "../includes/my.h"

char *to_bin(shell_t *shell, char *command)
{
    char **path = my_str_to_word_array(get_env_var(shell, "PATH"), ':');
    char *exec;

    if (access(command, 0) == 0)
        return command;
    command = my_strcat("/", command);
    for (int i = 0; path[i] != NULL; i++) {
        exec = my_strcat(path[i], command);
        if (access(exec, 0) == 0)
            return exec;
    }
    return "";
    free_array(path);
}

void my_exec(shell_t *shell)
{
    char *exec = to_bin(shell, shell->command[0]);
    pid_t pid = fork();
    int status;

    if (pid == 0) {
        if (execve(exec, shell->command, shell->env) != 0) {
            show_string(shell->command[0]);
            show_string(": Command not found.\n");
        }
        else if (signal(SIGSEGV, SIG_IGN))
            show_string("Segmentation fault\n");
        exit(0);
    }
    else
        waitpid(pid, &status, 0);
}

void execute_pipe(shell_t *shell, char *buff)
{
    char **commands = my_str_to_word_array(buff, '|');
    int fdPipe[2];
    pipe_t *pipes = malloc(sizeof(pipe_t));

    if (check_pipe_error(shell->buff) == 84)
        return;
    shell->command = commands;
    pipes->fd = fdPipe;
    pipes->save = 0;
    pipes->pid = parents(commands);
    pipes->max_len = nb_lines(commands);
    for (int i = 0; commands[i] != NULL; i++)
        execute_pipe2(shell, commands[i], i, pipes);
    waiting(pipes->pid, pipes->max_len);
}

void execute_separator(shell_t *shell)
{
    char **commands = my_str_to_word_array(shell->buff, ';');

    for (int i = 0; commands[i] != NULL; i++) {
        if (check_pipe(shell, commands[i]) > 0)
            continue;
        else
            execute(shell, commands[i]);
    }
}

void execute(shell_t *shell, char *command)
{
    void (*ptr[]) (shell_t *) = {my_cd, my_exit, show_env, my_setenv,
    my_unsetenv};
    const char *builtins[] = {"cd", "exit", "env", "setenv", "unsetenv"};
    int i = 0;

    command = remove_enter(command);
    shell->command = my_str_to_word_array(command, ' ');
    while (shell->command[i] != NULL)
        i++;
    shell->nb = i - 1;
    for (int i = 0 ; i < 5; i++) {
        if (my_strcmp(shell->command[0], builtins[i]) == 0) {
            ptr[i](shell);
            return;
        }
    }
    if (is_empty(shell->command[0]) == 1)
        return;
    my_exec(shell);
}