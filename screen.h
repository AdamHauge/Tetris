#ifndef GRID_H
#define GRID_H

#include <curses.h>
#include <deque>

#include "block.h"

#define SCREEN_WIDTH 10
#define SCREEN_HEIGHT 22
#define EMPTY_SPACE ' '

class Block;

typedef struct screen {
	char layout[SCREEN_HEIGHT][SCREEN_WIDTH];
	int color[SCREEN_HEIGHT][SCREEN_WIDTH];
	std::deque<Block *> lineup;
} screen_t;

screen_t initialize_grid();
void init_lineup(screen_t *screen);
void insert_lineup(screen_t *screen);
void print_screen(screen_t *screen);
int delete_lineup(screen_t *screen);
void clear_full_lines(screen_t *screen);
bool check_game_over(screen_t *screen);

#endif //GRID_H