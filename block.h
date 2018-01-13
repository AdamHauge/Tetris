#ifndef BLOCK_H
#define BLOCK_H

#include "screen.h"

typedef struct screen screen_t;

class Block {
protected:
	int x;
	int y;
	int width;
	int height;
	int color;
	char symbol;
	char shape[4][4];
	screen_t *screen;
	
	void reset_shape();
	
public:	
	Block(screen_t *screen);
	virtual ~Block() {}
	void move_down();
	void move_side(bool left);
	void fall();
	void print_block();
	void get_shape(char ret_shape[4][4]);
	char get_symbol();
	int get_color();
	virtual bool check_collision() = 0;
	virtual void rotate(bool clockwise) = 0;
	
private:
	void clear_block();
};

class I_Block : public Block {
public:
	I_Block(screen_t *screen);
	~I_Block() {}
	void rotate(bool clockwise);
	bool check_collision();
};

class Square : public Block {
public:
	Square(screen_t *screen);
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