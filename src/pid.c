/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-quentin.vandersteene
** File description:
** pid
*/

#include "../includes/my.h"

int nb_lines(char **temp)
{
    int i = 0;

    while (temp[i] != NULL)
        i++;
    return i;
}

int *init_table(int *table, char **temp)
{
    table = malloc(sizeof(int) * (nb_lines(temp) + 1));
    for (int i = 0; i != nb_lines(temp) + 1; i++)
        table[i] = -1;
    return table;
}

int *parents(char **temp)
{
    int *parent = NULL;
    int size = nb_lines(temp) + 1;
    
    parent = init_table(parent, temp);
    return parent;
}

void signal_seg(int pid)
{
    if (WIFSIGNALED(pid)) {
        if (WTERMSIG(pid) == 11)
            show_error("Segmentation fault");
        else if (WTERMSIG(pid) == 8)
            show_error("Floating exception");
    }
}

void waiting(int *pid, int max)
{
    int status = 0;

    for (int i = max - 1; i != -1 ; i--) {
        waitpid(pid[i], &status, 0);
        signal_seg(pid[i]);
    }
    free(pid);
}