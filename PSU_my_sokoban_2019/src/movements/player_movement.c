/*
** EPITECH PROJECT, 2019
** player_movement.c
** File description:
** player_movement
*/

#include "my_sokoban.h"
#include <stdlib.h>
#include <ncurses.h>

void player_move_up(ms_map_t *warehouse, ms_position_t *player_pos)
{
    int player_x = player_pos->x;
    int player_y = player_pos->y;

    if (warehouse->map[player_y - 1][player_x] == '#') {
        return;
    }
    if (warehouse->map[player_y - 1][player_x] == 'X') {
        if (warehouse->map[player_y - 2][player_x] == '#' || \
warehouse->map[player_y - 2][player_x] == 'X')
            return;
        warehouse->map[player_y - 2][player_x] = 'X';
    }
    warehouse->map[player_y][player_x] = warehouse->check_map[player_y]\
[player_x];
    warehouse->map[player_y - 1][player_x] = 'P';
    player_pos->y--;
}

void player_move_down(ms_map_t *warehouse, ms_position_t *player_pos)
{
    int player_x = player_pos->x;
    int player_y = player_pos->y;

    if (warehouse->map[player_y + 1][player_x] == '#') {
        return;
    }
    if (warehouse->map[player_y + 1][player_x] == 'X') {
        if (warehouse->map[player_y + 2][player_x] == '#' || \
warehouse->map[player_y + 2][player_x] == 'X')
            return;
        warehouse->map[player_y + 2][player_x] = 'X';
    }
    warehouse->map[player_y][player_x] = warehouse->check_map[player_y]\
[player_x];
    warehouse->map[player_y + 1][player_x] = 'P';
    player_pos->y++;
}

void player_move_left(ms_map_t *warehouse, ms_position_t *player_pos)
{
    int player_x = player_pos->x;
    int player_y = player_pos->y;

    if (warehouse->map[player_y][player_x - 1] == '#') {
        return;
    }
    if (warehouse->map[player_y][player_x - 1] == 'X') {
        if (warehouse->map[player_y][player_x - 2] == '#' || \
warehouse->map[player_y][player_x - 2] == 'X')
            return;
        warehouse->map[player_y][player_x - 2] = 'X';
    }
    warehouse->map[player_y][player_x] = warehouse->check_map[player_y]\
[player_x];
    warehouse->map[player_y][player_x - 1] = 'P';
    player_pos->x--;
}

void player_move_right(ms_map_t *warehouse, ms_position_t *player_pos)
{
    int player_x = player_pos->x;
    int player_y = player_pos->y;

    if (warehouse->map[player_y][player_x + 1] == '#') {
        return;
    }
    if (warehouse->map[player_y][player_x + 1] == 'X') {
        if (warehouse->map[player_y][player_x + 2] == '#' || \
warehouse->map[player_y][player_x + 2] == 'X')
            return;
        warehouse->map[player_y][player_x + 2] = 'X';
    }
    warehouse->map[player_y][player_x] = warehouse->check_map[player_y]\
[player_x];
    warehouse->map[player_y][player_x + 1] = 'P';
    player_pos->x++;
}

void movement_detection(ms_map_t *warehouse, int key)
{
    if (key == KEY_UP) {
        player_move_up(warehouse, warehouse->player->position);
    }
    if (key == KEY_DOWN) {
        player_move_down(warehouse, warehouse->player->position);
    }
    if (key == KEY_LEFT) {
        player_move_left(warehouse, warehouse->player->position);
    }
    if (key == KEY_RIGHT) {
        player_move_right(warehouse, warehouse->player->position);
    }
}