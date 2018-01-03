#include "block.h"
#include <curses.h>

Square::Square(grid_t *grid) : Block(grid)
{
	width = 2;
	height = 2;
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			shape[i][j] = 'X';
		}
	}
}

void Square::print_block()
{
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			grid->layout[y + i][x + j] = shape[i][j];
		}
	}
}

bool Square::check_collision()
{	for(int i = 0; i < width; i++) {
		if(' ' != grid->layout[y + height][x + i]) {
			return true;
		}
	}
	return false;
}