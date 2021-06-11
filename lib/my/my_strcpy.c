/*
** EPITECH PROJECT, 2020
** my_strcpy.c
** File description:
** Quentin.vandersteene@epitech.eu
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    while (dest[i] != '\0') {
        dest[i] = '\0';
        i++;
    }
    return dest;
}
