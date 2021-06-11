/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-quentin.vandersteene
** File description:
** free
*/

#include "../includes/my.h"

void free_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

void free_all(shell_t *shell)
{
    if (shell->command)
        free_array(shell->command);
    free(shell);
}