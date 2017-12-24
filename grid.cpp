#include "grid.h"

grid_t initialize_grid()
{
	grid_t grid;
	for(int i = 0; i < screen_height; i++) {
		for(int j = 0; j < screen_width; j++) {
			grid.layout[i][j] = '.';
		}
	}
	
	return grid;
}

void print_screen(grid_t *grid)
{
	/* print top and bottom borders */
	for(int i = 0; i < screen_width + 2; i++) {
		mvaddch(1, i, '*');
		mvaddch(22, i, '*');
	}
	
	/* print side borders */
	for(int i = 2; i < screen_height; i++) {
		mvaddch(i, 0, '*');
		mvaddch(i, screen_width + 1, '*');
	}
	
	/* print grid */
	for(int i = 2; i < screen_height; i++) {
		for(int j = 0; j < screen_width; j++) {
			mvaddch(i, j + 1, grid->layout[i][j]);
		}
	}
}