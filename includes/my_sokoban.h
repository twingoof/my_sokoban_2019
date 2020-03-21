/*
** EPITECH PROJECT, 2019
** my_sokoban.h
** File description:
** my_sokoban
*/

#ifndef MY_SOKOBAN_H_
#define MY_SOKOBAN_H_

#define SUCCESS 0
#define FAILURE 84
#define LOSE 1
#define USAGE "USAGE\n \
./my_sokoban map\n \
use arrow keys to move\n \
e to ecit and spacebar to reset map\n \
DESCRIPTION\n \
map : file representing the warehouse map, containing '#' for wall, 'P' for \
player, 'X' for boxes and 'O' for storage locations"

typedef struct ms_entity_s ms_entity_t;
typedef struct ms_map_s ms_map_t;
typedef struct ms_position_s ms_position_t;

struct ms_position_s{
    int x;
    int y;
};

struct ms_entity_s{
    ms_position_t *position;
    ms_entity_t *next;
    ms_entity_t *first;
};

struct ms_map_s{
    int width;
    int height;
    int barrel_ctr;
    int storage_ctr;
    char *backup;
    char **map;
    char **check_map;
    ms_entity_t *player;
};

void my_putchar(char character);
void my_putstr(char const *string);
int my_putnbr(int number);
int sokoban(char *map_path);
char **load_map(char const *map);
int game(ms_map_t *warehouse);
void movement_detection(ms_map_t *warehouse, int key);
char **clean_map(char **map);
int barrel_move_up(ms_map_t *warehouse, ms_entity_t *barrel);
void find_entity(ms_map_t *warehouse);

#endif /* !MY_SOKOBAN_H_ */
