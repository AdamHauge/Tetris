#include "controls.h"

int get_input(Block *b)
{
	switch(getch()) {
		case 'a':
			b->move_side(true);
			break;
		case 'd':
			b->move_side(false);
			break;
		case 'q':
			return 1;
		case 's':
			b->fall();
			break;
		case 'z':
			b->rotate(false);
			break;
		case 'c':
			b->rotate(true);
			break;
		default:
			b->move_down();
			break;
	}
	
	return 0;
}