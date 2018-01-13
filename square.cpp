#include "block.h"
#include <curses.h>

Square::Square(grid_t *grid) : Block(grid)
{
	width = 2;
	height = 2;
	color = COLOR_GREEN;
	
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			shape[i][j] = 'X';
		}
	}
}

void Square::rotate(bool clockwise) 
{
	move_down();
}

bool Square::check_collision()
{	
	for(int i = 0; i < width; i++) {
		if(' ' != grid->layout[y + height][x + i]) {
			return true;
		}
	}
	return false;
}