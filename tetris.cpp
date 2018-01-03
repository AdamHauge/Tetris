#include <curses.h>
#include <iostream>
#include <unistd.h>

#include "grid.h"
#include "block.h"
#include "controls.h"

int main(int argc, char *argv[])
{
	/* Initialize the game */
	grid_t grid = initialize_grid();
	init_lineup(&grid);
	
	/* Initialize the screen */
	initscr();
	print_screen(&grid);
	curs_set(0);
	noecho();
	cbreak();
	timeout(0);
	
	while(false == check_game_over(&grid)) {
		/* Take the first block from the lineup */
		Block *b = grid.lineup.front();
		grid.lineup.pop_front();
		grid.lineup.push_back(new Square(&grid));
		
		/* Print the block at the top of the screen */
		b->print_block();
		print_screen(&grid);
		refresh();
		sleep(1);
		
		/* Move block down until collision detected */
		while(false == b->check_collision()) {
			
			/* Move block and re-print */
			/* Press 'q' to quit */
			if(get_input(b)) {
				goto GAMEOVER;
			}
			print_screen(&grid);
			refresh();
			sleep(1);
			
		}
		refresh();
		delete b;
		if(getch() == 'q') break;
	}
	GAMEOVER:
	
	/* Close curses window */
	endwin();
	
	std::cout << "Game Over" << std::endl;
	delete_lineup(&grid);
	
	return 0;
}