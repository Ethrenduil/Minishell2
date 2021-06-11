/*
** EPITECH PROJECT, 2020
** my_swap.c
** File description:
** quentin.vandersteene@epitech.eu
*/

void my_putchar(char a);

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
    return;
}