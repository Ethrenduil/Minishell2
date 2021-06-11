/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-quentin.vandersteene
** File description:
** my
*/

#ifndef my
#define my


#define MALLOC        "MALLOC IMPOSSIBLE"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct pipe_s {
    int *fd;
    int save;
    int *pid;
    int max_len;
}pipe_t;

typedef struct s_shell
{
    char **env;
    char **command;
    char *buff;
    int nb;
    int special;
} shell_t;

// Lib.a

void my_putchar(char c);
int show_number(int nb);
void show_string(char const *str);
char *reverse_string(char *str);
int to_number(char const *str);
int is_prime_number(int nb);
char *my_strcpy(char *dest, char const *src);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strstr(char *str, char const *to_find);
int my_strlen(char const *str);
char **my_str_to_word_array(char *str, char c);
void show_params(int nb, char **arg);
int is_alphanum(char c);
int is_alpha(char c);
void my_puterror(char c);
int show_error(char const *str);
int nb_arg(int nb);
int is_number(char c);
int is_signe(char c);
int my_to_number(char *str);
int char_number(char *nb);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char *src);

// clean.c

char *remove_space(char *str);
char *remove_tab(char *str);
char *clean_input(char *str);
void clean_all(shell_t *shell);

// env.c

void show_env(shell_t *shell);
void my_setenv(shell_t *shell);
void change_var(shell_t *shell, int line, char *name, char *value);
void add_var(shell_t *shell, char *var, char *content);

// env2.c

void my_unsetenv(shell_t *shell);

// parsing.c

void  parse(shell_t *shell);
int is_empty(char *str);

// execute.c

void execute(shell_t *shell, char *command);
void execute_separator(shell_t *shell);
char *remove_enter(char *command);
void execute_pipe(shell_t *shell, char *buff);

// my_shell.c

void my_exit(shell_t *shell);
void replace_oldpwd(shell_t * shell);
char *get_env_var(shell_t *shell, char *look);
void replace_pwd(shell_t *shell);
int *go_tab(int *tab, int elem, int max);

// my_cd.c

void my_cd(shell_t *shell);

// check.c

int check_separator(shell_t *shell);
int check_pipe(shell_t *shell, char *buff);
int check_redirection(shell_t *shell);

// pipe.c

int check_pipe_error(char *command);
int nb_lines(char **temp);
void waiting(int *pid, int max);
void execute_pipe2(shell_t *shell, char *command, int i, pipe_t *pipes);

// pid.c

int nb_lines(char **temp);
int *parents(char **temp);
void waiting(int *pid, int max);

// free.c

void free_all(shell_t *shell);
void free_array(char **array);

#endif /* !my */
