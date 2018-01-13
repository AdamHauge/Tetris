#include <curses.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <time.h>

#include "screen.h"
#include "block.h"
#include "controls.h"

int main(int argc, char *argv[])
{
	/* Initialize the game */
	srand(time(NULL));
	screen_t screen = initialize_grid();
	init_lineup(&screen);
	
	/* Initialize the screen */
	initscr();
	start_color();
	curs_set(0);
	noecho();
	cbreak();
	timeout(0);
	
	print_screen(&screen);
	refresh();
	
	while(false == check_game_over(&screen)) {
		/* Take the first block from the lineup */
		Block *b = screen.lineup.front();
		screen.lineup.pop_front();
		insert_lineup(&screen);
		
		/* Print the block at the top of the screen */
		b->print_block();
		print_screen(&screen);
		refresh();
		sleep(1);
		
		/* Move block down until collision detected */
		while(false == b->check_collision()) {
			
			/* Move block and re-print */
			/* Press 'q' to quit */
			if(get_input(b)) {
				delete b;
				goto GAMEOVER;
			}
			print_screen(&screen);
			refresh();
			sleep(1);
			
		}
		
		clear_full_lines(&screen);
		refresh();
		delete b;
		if(getch() == 'q') break;
	}
	GAMEOVER:
	
	/* Close curses window */
	endwin();
	
	std::cout << "Game Over" << std::endl;
	delete_lineup(&screen);
	
	return 0;
}