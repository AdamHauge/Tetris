#include "block.h"
#include <curses.h>

Square::Square(grid_t *grid) : Block(grid)
{
	width = 2;
	height = 2;
}

void Square::print_block()
{
	attron(COLOR_GREEN);
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			grid->layout[y + i][x + j] = '*';
		}
	}
}

bool Square::check_collision()
{
	return ('*' == grid->layout[y + height][x]);
}