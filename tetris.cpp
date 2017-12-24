#include <curses.h>

#include "grid.h"

int main(int argc, char *argv[])
{
	grid_t grid = initialize_grid();
	initscr();
	print_screen(&grid);
	getch();
	endwin();
	
	return 0;
}