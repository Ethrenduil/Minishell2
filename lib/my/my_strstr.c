/*
** EPITECH PROJECT, 2020
** my_strstr.c
** File description:
** Quentin.vandersteene@epitech.eu
*/

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == to_find[0]) {
            return &str[i];
        }
        i++;
    }
    return 0;
}