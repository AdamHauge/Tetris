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
	char block[3][3];
	grid_t *grid;
	
public:	
	Block(grid_t *grid);
	virtual ~Block() {}
	void move_down();
	void move_side(bool left);
	virtual void print_block() = 0;
	virtual bool check_collision() = 0;
	//virtual void rotate() = 0;
	
private:
	void clear_block();
};

class I_Block : public Block {
	
};

class Square : public Block {
public:
	Square(grid_t *grid);
	~Square() {}
	void print_block();
	bool check_collision();
	
private:
	char shape[2][2];
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