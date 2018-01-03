#ifndef BLOCK_H
#define BLOCK_H

#include "grid.h"

typedef struct grid grid_t;

class Block {
protected:
	int x;
	int y;
	int width;
	int height;
	int color;
	char shape[4][4];
	grid_t *grid;
	
public:	
	Block(grid_t *grid);
	virtual ~Block() {}
	void move_down();
	void move_side(bool left);
	void fall();
	void print_block();
	virtual bool check_collision() = 0;
	virtual void rotate(bool clockwise) = 0;
	
private:
	void clear_block();
};

class I_Block : public Block {
	
};

class Square : public Block {
public:
	Square(grid_t *grid);
	~Square() {}
	void rotate(bool clockwise);
	bool check_collision();
};

class T_Block : public Block {
	
};

class S_Block : public Block {
	
};

class Z_Block : public Block {
	
};

class J_Block : public Block {
	
};

class L_Block : public Block {
	
};

#endif //BLOCK_H