/*
** EPITECH PROJECT, 2020
** my_strncpy.c
** File description:
** Quentin.vandersteene@epitech.eu
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n ; i++) {
        if (src[i])
            dest[i] = src[i];
        else
            dest[i] = '\0';
    }
    return dest;
}