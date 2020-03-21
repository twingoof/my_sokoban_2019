/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include <stdlib.h>
#include "my_sokoban.h"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (FAILURE);
    else if (argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr(USAGE);
        return (FAILURE);
    } else {
        return(sokoban(argv[1]));
    }
}