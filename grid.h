#include <curses.h>

#define screen_width 10
#define screen_height 22

typedef struct {
	char layout[screen_height][screen_width];
} grid_t;

grid_t initialize_grid();
void print_screen(grid_t *grid);