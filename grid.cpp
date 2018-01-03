#include "grid.h"

grid_t initialize_grid()
{
	grid_t grid;
	for(int i = 0; i < screen_height; i++) {
		for(int j = 0; j < screen_width; j++) {
			if((i != 0) && (i == screen_height - 1 || (j == 0 || j == screen_width - 1))) {
				grid.layout[i][j] = '*';
			}
			else {
				grid.layout[i][j] = ' ';
			}
		}
	}
	
	return grid;
}

void init_lineup(grid_t *grid)
{
	for(int i = 0; i < 3; i++) {
		Block *b = new Square(grid);
		grid->lineup.push_back(b);
	}
}

void print_screen(grid_t *grid)
{
	/* print grid */
	attron(COLOR_GREEN);
	for(int i = 0; i < screen_height; i++) {
		for(int j = 0; j < screen_width; j++) {
			mvaddch(i, j + 1, grid->layout[i][j]);
		}
	}
	attroff(COLOR_GREEN);
}

bool check_game_over(grid_t *grid)
{
	for(int i = 1; i < screen_width - 1; i++) {
		if('*' == grid->layout[1][i]) {
			return true;
		}
	}
	return false;
}

int delete_lineup(grid_t *grid)
{
	while(grid->lineup.size() > 0) {
		delete grid->lineup.back();
		grid->lineup.pop_back();
	}
	
	return grid->lineup.size();
}