#include "block.h"
#include <curses.h>

Square::Square(screen_t *screen) : Block(screen)
{
	width = 2;
	height = 2;
	color = COLOR_GREEN;
	symbol = 'X';
	
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			shape[i][j] = symbol;
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
		if(' ' != screen->layout[y + height][x + i]) {
			return true;
		}
	}
	return false;
}