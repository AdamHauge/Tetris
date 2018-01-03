#include "block.h"
#include <curses.h>
#include <iostream>

void clear_block();

Block::Block(grid_t *grid)
{
	this->grid = grid;
	x = screen_width / 2;
	y = 0;
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
	if(left) {
		x--;
	} else {
		x++;
	}
	
	move_down();
}

void Block::clear_block()
{
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			grid->layout[y + i][x + j] = ' ';
		}
	}
}