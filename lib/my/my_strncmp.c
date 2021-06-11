/*
** EPITECH PROJECT, 2020
** my_strncmp.c
** File description:
** Quentin.vandersteene@epitech.eu
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int changed = 0;
    int i = 0;

    while (s1[i] && s2[i])
    {
        if (s1[i] < s2[i])
            changed--;
        else if (s1[i] > s2[i])
            changed++;
        i++;
    }
    return changed;
}