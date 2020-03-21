/*
** EPITECH PROJECT, 2019
** sokoban.c
** File description:
** sokoban
*/

#include <ncurses.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "my_sokoban.h"

void entity_init(ms_map_t *warehouse)
{
    warehouse->player = malloc(sizeof(ms_entity_t));
    warehouse->player->position = malloc(sizeof(ms_position_t));
    warehouse->player->position->x = 0;
    warehouse->player->position->y = 0;
    warehouse->storage_ctr = 0;
}

void find_entity(ms_map_t *warehouse)
{
    entity_init(warehouse);
    for (int y = 0; warehouse->map[y] != NULL; y++) {
        for (int x = 0; warehouse->map[y][x] != '\0'; x++) {
            if (warehouse->map[y][x] == 'P') {
                warehouse->player->position->x = x;
                warehouse->player->position->y = y;
            }
            if (warehouse->map[y][x] == 'O') {
                warehouse->storage_ctr++;
            }
            if (warehouse->map[y][x] == 'X') {
                warehouse->barrel_ctr++;
            }
        }
    }
}

void find_height(ms_map_t *warehouse, char *buff)
{
    int columns = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        columns ++;
        if (buff[i] == '\n' && columns > warehouse->width) {
            warehouse->height ++;
            warehouse->width = columns;
            columns = 0;
        } else if (buff[i] == '\n' && columns <= warehouse->width) {
            warehouse->height ++;
            columns = 0;
        }
    }
}

void get_size(ms_map_t *warehouse)
{
    int fd = open(warehouse->backup, O_RDONLY);
    char *buff;
    struct stat infos;

    warehouse->width = 0;
    warehouse->height = 0;
    if (fd < 0)
        exit(FAILURE);
    fstat(fd, &infos);
    buff = malloc(sizeof(char) * infos.st_size);
    read(fd, buff, infos.st_size);
    find_height(warehouse, buff);
    free(buff);
}

int sokoban(char *map_path)
{
    int out;
    ms_map_t *warehouse = malloc(sizeof(ms_map_t));

    warehouse->backup = map_path;
    warehouse->map = load_map(map_path);
    warehouse->check_map = load_map(map_path);
    warehouse->check_map = clean_map(warehouse->check_map);
    find_entity(warehouse);
    get_size(warehouse);
    initscr();
    out = game(warehouse);
    endwin();
    free(warehouse);
    return out;
}