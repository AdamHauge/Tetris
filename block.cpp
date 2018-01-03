#include "block.h"
#include <curses.h>
#include <iostream>

void clear_block();

Block::Block(grid_t *grid)
{
	this->grid = grid;
	x = (screen_width / 2) - 1;
	y = 0;
}

void Block::print_block()
{
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			if('X' == shape[i][j]) {
				grid->color[y + i][x + j] = color;
				grid->layout[y + i][x + j] = shape[i][j];
			}
		}
	}
}

void Block::move_down()
{
	clear_block();
	y++;
	print_block();
}

void Block::move_side(bool left)
{
	clear_block();
	if(left && ' ' == grid->layout[y][x - 1]) {
		x--;
	} else if(!left && ' ' == grid->layout[y][x + width]) {
		x++;
	}
	
	move_down();
}

void Block::fall()
{
	clear_block();
	
	while(false == check_collision()) {
		y++;
	}
	
	print_block();
}

void Block::clear_block()
{
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			//grid->color[i][j] = COLOR_BLACK;
			grid->layout[y + i][x + j] = ' ';
		}
	}
}