/*
** EPITECH PROJECT, 2020
** my_is_prime.c
** File description:
** Quentin.Vandersteene@epitech.eu
*/

int my_is_prime(int nb)
{
    int a = 0;

    for (int i = 1; i <= nb; i++){
        if (nb % i == 0)
        {
            a++;
        }
    }
    if (a == 2)
        return 1;
    else
        return 0;
}