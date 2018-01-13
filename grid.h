#ifndef GRID_H
#define GRID_H

#include <curses.h>
#include <deque>

#include "block.h"

#define SCREEN_WIDTH 10
#define SCREEN_HEIGHT 22
#define EMPTY_SPACE ' '

class Block;

typedef struct grid {
	char layout[SCREEN_HEIGHT][SCREEN_WIDTH];
	int color[SCREEN_HEIGHT][SCREEN_WIDTH];
	std::deque<Block *> lineup;
} grid_t;

grid_t initialize_grid();
void init_lineup(grid_t *grid);
void insert_lineup(grid_t *grid);
void print_screen(grid_t *grid);
int delete_lineup(grid_t *grid);
void clear_full_lines(grid_t *grid);
bool check_game_over(grid_t *grid);

#endif //GRID_H