#include "game.h"

static int total_points = 0; /* current score */
static bool tetris = false; /* state of previous turn being a tetris */

int get_input(Block *b)
{
	switch(getch()) {
		case 'a': /* move left */
			b->move_side(true);
			break;
		case 'd': /* move right */
			b->move_side(false);
			break;
		case 'q': /* quit */
			return 1;
		case 's': /* hard fall */
			b->fall();
			break;
		case 'z': /* rotate clockwise */
			b->rotate(false);
			break;
		case 'c': /* rotate counter-clockwise */
			b->rotate(true);
			break;
		default: /* do nothing */
			b->move_down();
			break;
	}
	
	return 0;
}

bool check_tetris(int new_tetris)
{
	switch(new_tetris) {
		case -1: /* do nothing */
			break;
		case 0:
			/* intentional fallthrough */
		case 1:
			tetris = new_tetris; /* update tetris state */
			break;
		default:
			break;
	}
	return tetris;
}

int calculate_points(int num_rows)
{
	/* -1 just returns score */
	if(-1 == num_rows) {
		return total_points;
	}
	
	/* number of points == 100 * number of cleared rows... */
	int score = num_rows * 100;
	
	/* ... a tetris results in 800 points */
	if(4 == num_rows) {
		score = 800;
		check_tetris(true);
		
		/* back to back tetris results in 1200 points */
		if(check_tetris(-1)) {
			score = 1200;
		}
	}
	else {
		/* update the current tetris state */
		check_tetris(false);
	}
	
	/* update total score */
	total_points += score;
	
	return total_points;
}

int update_score(int num_rows)
{
	return calculate_points(num_rows);
}

void print_score()
{
	/* print score to the screen */
	mvprintw(SCREEN_HEIGHT - 1, SCREEN_WIDTH + 5, "Score: %d", update_score(-1));
}