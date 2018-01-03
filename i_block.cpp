#include "block.h"

#include <algorithm>

I_Block::I_Block(grid_t *grid) : Block(grid)
{
	width = 1;
	height = 4;
	color = COLOR_RED;
	
	for(int i = 0; i < 4; i++) {
		shape[i][0] = 'I';
	}
}

void I_Block::rotate(bool clockwise)
{
	if(1 == height) {
		for(int i = 1; i < 4; i++) {
			if(' ' != grid->layout[y + i][x]) {
				move_down();
				return;
			}
		}
	}
	
	else if(4 == height) {
		for(int i = 1; i < 4; i++) {
			if(' ' != grid->layout[y][x + i]) {
				move_down();
				return;
			}
		}
	}
	
	reset_shape();
	std::swap(width, height);
	
	if(1 == height) {		
		for(int i = 0; i < 4; i++) {
			shape[0][i] = 'I';
		}
	}
	
	else if(4 == height) {		
		for(int i = 0; i < 4; i++) {
			shape[i][0] = 'I';
		}
	}
	
	move_down();
}
	
bool I_Block::check_collision()
{
	for(int i = 0; i < width; i++) {
		if(' ' != grid->layout[y + height][x + i]) {
			return true;
		}
	}
	return false;
}