#include "screen.h"
#include <cstdlib>

screen_t initialize_grid()
{
	screen_t screen;
	
	for(int i = 0; i < SCREEN_HEIGHT; i++) {
		for(int j = 0; j < SCREEN_WIDTH; j++) {
			/* create border */
			if((i != 0) && (i == SCREEN_HEIGHT - 1 || (j == 0 || j == SCREEN_WIDTH - 1))) {
				screen.layout[i][j] = '*';
				screen.color[i][j] = COLOR_WHITE;
			}
			/* non-border */
			else {
				screen.layout[i][j] = EMPTY_SPACE;
				screen.color[i][j] = COLOR_BLACK;
			}
		}
	}
	
	return screen;
}

Block * random_block(screen_t *screen)
{
	switch(rand() % 2) {
		case 0:
			return new Square(screen);
		case 1:
			return new I_Block(screen);
		default:
			endwin();
			return NULL;
	}
}

void init_lineup(screen_t *screen)
{
	/* create queue of next three blocks */
	for(int i = 0; i < 3; i++) {
		screen->lineup.push_back(random_block(screen));
	}
}

void insert_lineup(screen_t *screen)
{
	/* insert random block */
	screen->lineup.push_back(random_block(screen));
}

void print_lineup(screen_t *screen)
{
	for(int i = 0; i < 15; i++) {
		for(int j = 0; j < 6; j++) {
			mvaddch(i + 1, j + SCREEN_WIDTH + 2, '*');
		}
	}
	
	for(unsigned int curr = 0; curr < screen->lineup.size(); curr++) {	
		char shape[4][4];
		Block *block = screen->lineup[curr];
		char symbol = block->get_symbol();
		int color = block->get_color();
		block->get_shape(shape);
		
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++) {
				attron(COLOR_PAIR(color));
				switch(curr) {
					case 0:
						mvaddch(i + 1, j + SCREEN_WIDTH + 3, symbol == shape[i][j] ? symbol : EMPTY_SPACE);
						break;
					case 1:
						mvaddch(i + 6, j + SCREEN_WIDTH + 3, symbol == shape[i][j] ? symbol : EMPTY_SPACE);
						break;
					case 2:
						mvaddch(i + 11, j + SCREEN_WIDTH + 3, symbol == shape[i][j] ? symbol : EMPTY_SPACE);
						break;
				}
				attroff(COLOR_PAIR(color));
			}
		}
	}
}

void print_screen(screen_t *screen)
{
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	
	/* print screen */
	for(int i = 0; i < SCREEN_HEIGHT; i++) {
		for(int j = 0; j < SCREEN_WIDTH; j++) {
			attron(COLOR_PAIR(screen->color[i][j]));
			mvaddch(i, j + 1, screen->layout[i][j]);
			attroff(COLOR_PAIR(screen->color[i][j]));
		}
	}
	
	print_lineup(screen);
}

bool check_game_over(screen_t *screen)
{
	/* If next block collides with top row game over */
	for(int i = 1; i < SCREEN_WIDTH - 1; i++) {
		if(' ' != screen->layout[1][i]) {
			return true;
		}
	}
	return false;
}

void clear_line(screen_t *screen, int line)
{
	/* Clear out full line */
	for(int i = 1; i < SCREEN_WIDTH - 1; i++) {
		screen->layout[line][i] = ' ';
		screen->color[line][i] = COLOR_BLACK;
	}
	
	/* Move all above lines down by one */
	for(int i = line; i > 1; i--) {
		for(int j = 1; j < SCREEN_WIDTH - 1; j++) {
			screen->layout[i][j] = screen->layout[i - 1][j];
			screen->color[i][j] = screen->color[i - 1][j];
		}
	}
}

void clear_full_lines(screen_t *screen)
{
	/* Check if any lines are full */
	for(int i = 0; i < SCREEN_HEIGHT - 1; i++) {
		bool full = true;
		
		for(int j = 0; j < SCREEN_WIDTH; j++) {
			if(' ' == screen->layout[i][j]) {
				full = false;
				break;
			}
		}
		
		/* If line is full, clear it */
		if(true == full) {
			refresh();
			clear_line(screen, i);
		}
	}
}

int delete_lineup(screen_t *screen)
{
	/* delete every block in lineup */
	while(0 < screen->lineup.size()) {
		delete screen->lineup.back();
		screen->lineup.pop_back();
	}
	
	return screen->lineup.size();
}