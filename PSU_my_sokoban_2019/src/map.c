/*
** EPITECH PROJECT, 2019
** map.c
** File description:
** load map for my_sokoban
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_sokoban.h"

void is_valid(char *map)
{
    int invalid = 0;
    char valid_char[7] = {'#', ' ', 'O', 'P', 'X', '\n', 0};

    if (map[0] == '\0')
        exit(FAILURE);
    for (int i = 0; map[i] != '\0'; i++) {
        invalid = 0;
        for (int j = 0; valid_char[j] != 0; j++) {
            if (map[i] != valid_char[j])
                invalid++;
            if (invalid == 6)
                exit(FAILURE);
        }
    }
}

char ** char_array_malloc(char *map, int height)
{
    char **solved_map = malloc(sizeof(char *) * height + 1);
    int line_length = 0;

    solved_map[height] = NULL;
    for (int i = 0; map[i] != '\n'; i++)
        line_length ++;
    for (int i = 0; i < height; i++)
        solved_map[i] = malloc(sizeof(char) * line_length * 3);
    return solved_map;
}

char **str_to_array(char *str, int size)
{
    char **map;

    map = char_array_malloc(str, size);
    for (int i = 0, a = 0, b = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            map[a][b] = '\n';
            map[a][b + 1] = '\0';
            a++;
            b = 0;
        } else {
            map[a][b] = str[i];
            b++;
        }
    }
    return (map);
}

char **load_map(char const *map_path)
{
    int fd = open(map_path, O_RDONLY);
    char *buff;
    char **map;
    struct stat infos;

    if (fd < 0)
        exit(FAILURE);
    fstat(fd, &infos);
    buff = malloc(sizeof(char) * infos.st_size);
    read(fd, buff, infos.st_size);
    is_valid(buff);
    map = str_to_array(buff, infos.st_size);
    free(buff);
    return (map);
}

char **clean_map(char **map)
{
    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\0'; x++) {
            if (map[y][x] == 'P' || map[y][x] == 'X')
                map[y][x] = ' ';
        }
    }
    return (map);
}