/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** display each character of a string.
*/

#include <stdlib.h>
#include <unistd.h>


void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    int n;
    for (n = 0; str[n] != '\0'; n++) {
        my_putchar(str[n]);
    }
}

int my_putnbr(int nb)
{
    int number;
    if (nb == -2147483648) {
        return 84;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10) {
        number = nb % 10;
        nb = nb / 10;
        my_putnbr(nb);
        my_putchar(number + '0');
    }
    else {
        my_putchar(nb + '0');
    }
    return 0;
}