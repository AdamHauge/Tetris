#ifndef GAME_H
#define GAME_H

#include <curses.h>
#include "block.h"
int get_input(Block *b);
int update_score(int num_rows);
void print_score();
#endif