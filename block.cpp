#include "block.h"
#include <curses.h>
#include <iostream>

Block::Block(screen_t *screen)
{
	this->screen = screen;
	x = (SCREEN_WIDTH / 2) - 1;
	y = 0;
}

void Block::print_block()
{
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			if(' ' != shape[i][j]) {
				screen->color[y + i][x + j] = color;
				screen->layout[y + i][x + j] = shape[i][j];
			}
		}
	}
}

void Block::get_shape(char ret_shape[4][4])
{	
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			ret_shape[i][j] = shape[i][j];
		}
	}
}

char Block::get_symbol()
{
	return symbol;
}

int Block::get_color()
{
	return color;
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
	if(left && EMPTY_SPACE == screen->layout[y][x - 1]) {
		x--;
	} else if(!left && EMPTY_SPACE == screen->layout[y][x + width]) {
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
			screen->layout[y + i][x + j] = ' ';
		}
	}
}

void Block::reset_shape() 
{
	clear_block();
	
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			shape[i][j] = ' ';
		}
	}
}