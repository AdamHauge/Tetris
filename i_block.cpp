#include "block.h"

#include <algorithm>

I_Block::I_Block(screen_t *screen) : Block(screen)
{
	width = 1;
	height = 4;
	color = COLOR_RED;
	symbol = 'I';
	
	for(int i = 0; i < 4; i++) {
		shape[i][0] = symbol;
	}
}

void I_Block::rotate(bool clockwise)
{
	if(1 == height) {
		for(int i = 1; i < 4; i++) {
			if(' ' != screen->layout[y + i][x]) {
				move_down();
				return;
			}
		}
	}
	
	else if(4 == height) {
		for(int i = 1; i < 4; i++) {
			if(' ' != screen->layout[y][x + i]) {
				move_down();
				return;
			}
		}
	}
	
	reset_shape();
	std::swap(width, height);
	
	if(1 == height) {		
		for(int i = 0; i < 4; i++) {
			shape[0][i] = symbol;
		}
	}
	
	else if(4 == height) {		
		for(int i = 0; i < 4; i++) {
			shape[i][0] = symbol;
		}
	}
	
	move_down();
}
	
bool I_Block::check_collision()
{
	for(int i = 0; i < width; i++) {
		if(' ' != screen->layout[y + height][x + i]) {
			return true;
		}
	}
	return false;
}