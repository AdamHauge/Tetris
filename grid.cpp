#include "grid.h"

grid_t initialize_grid()
{
	grid_t grid;
	
	for(int i = 0; i < screen_height; i++) {
		for(int j = 0; j < screen_width; j++) {
			/* create border */
			if((i != 0) && (i == screen_height - 1 || (j == 0 || j == screen_width - 1))) {
				grid.layout[i][j] = '*';
				grid.color[i][j] = COLOR_WHITE;
			}
			/* non-border */
			else {
				grid.layout[i][j] = ' ';
			}
		}
	}
	
	return grid;
}

void init_lineup(grid_t *grid)
{
	/* create queue of next three blocks */
	for(int i = 0; i < 3; i++) {
		Block *b = new Square(grid);
		grid->lineup.push_back(b);
	}
}

void print_screen(grid_t *grid)
{
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	
	/* print grid */
	for(int i = 0; i < screen_height; i++) {
		for(int j = 0; j < screen_width; j++) {
			attron(COLOR_PAIR(grid->color[i][j]));
			mvaddch(i, j + 1, grid->layout[i][j]);
			attroff(COLOR_PAIR(grid->color[i][j]));
		}
	}
}

bool check_game_over(grid_t *grid)
{
	/* If next block collides with top row game over */
	for(int i = 1; i < screen_width - 1; i++) {
		if(' ' != grid->layout[1][i]) {
			return true;
		}
	}
	return false;
}

int delete_lineup(grid_t *grid)
{
	/* delete every block in lineup */
	while(0 < grid->lineup.size()) {
		delete grid->lineup.back();
		grid->lineup.pop_back();
	}
	
	return grid->lineup.size();
}