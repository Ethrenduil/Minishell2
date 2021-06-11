/*
** EPITECH PROJECT, 2020
** my_putchar.c
** File description:
** quentin.vandersteene@epitech.eu
*/

#include <unistd.h>

void my_puterror(char c)
{
    write (2 , &c, 1);
}