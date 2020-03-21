/*
** EPITECH PROJECT, 2019
** main_display.c
** File description:
** main_display
*/

#include <ncurses.h>
#include <stdlib.h>
#include "my_sokoban.h"

int is_blocked(char **map, int y, int x)
{
    int blocked[4] = {0, 0, 0, 0};

    if (map[y][x] == 'X' && (map[y - 1][x] == '#' || map[y - 1][x] == 'X'))
        blocked[0] ++;
    if (map[y][x] == 'X' && (map[y + 1][x] == '#' || map[y + 1][x] == 'X'))
        blocked[1] ++;
    if (map[y][x] == 'X' && (map[y][x - 1] == '#' || map[y][x - 1] == 'X'))
        blocked[2] ++;
    if (map[y][x] == 'X' && (map[y][x + 1] == '#' || map[y][x + 1] == 'X'))
        blocked[3] ++;
    return ((blocked[0] + blocked[1]) * (blocked[2] + blocked[3]));
}

int is_win(ms_map_t *warehouse)
{
    int occuped = 0;
    int blocked = 0;

    for (int y = 0; warehouse->map[y] != NULL; y++) {
        for (int x = 0; warehouse->map[y][x] != '\0'; x++) {
            if (warehouse->check_map[y][x] == 'O' && warehouse->map\
[y][x] == 'X')
                occuped++;
            else if (is_blocked(warehouse->map, y, x) != 0)
                blocked ++;
            if (occuped == warehouse->storage_ctr)
                return SUCCESS;
            if (blocked == warehouse->barrel_ctr)
                return LOSE;
        }
    }
    return FAILURE;
}

void display(ms_map_t *warehouse)
{
    if (LINES <= warehouse->height || COLS <= warehouse->width) {
        clear();
        mvprintw(LINES / 2, (COLS - 29) / 2, "Please enlarge your terminal");
    } else {
        clear();
        for (int i = 0; warehouse->map[i] != NULL; i++) {
            mvprintw(i, 0, warehouse->map[i]);
        }
        refresh();
    }
}

int game(ms_map_t *warehouse)
{
    int key = 0;

    keypad(stdscr, TRUE);
    while (key != 'e' && key != 'E') {
        noecho();
        if (key == ' ') {
            warehouse->map = load_map(warehouse->backup);
            find_entity(warehouse);
        }
        movement_detection(warehouse, key);
        display(warehouse);
        if (is_win(warehouse) == SUCCESS) {
            return SUCCESS;
        } else if (is_win(warehouse) == LOSE) {
            return LOSE;
        }
        key = getch();
    }
    return SUCCESS;
}
