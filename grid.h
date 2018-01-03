#ifndef GRID_H
#define GRID_H

#include <curses.h>
#include <deque>

#include "Block.h"

#define screen_width 10
#define screen_height 22

class Block;

typedef struct grid {
	char layout[screen_height][screen_width];
	std::deque<Block *> lineup;
} grid_t;

grid_t initialize_grid();
void init_lineup(grid_t *grid);
void print_screen(grid_t *grid);
int delete_lineup(grid_t *grid);
bool check_game_over(grid_t *grid);

#endif //GRID_H