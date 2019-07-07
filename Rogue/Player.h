#pragma once
#include "Object.h"
#include <curses.h>
class Player : public Object{
public:
	Player() {
		trow = 0;
		tcol = 0;
	};
	//Player(int row = 0, int col = 0) {};


	~Player();
	void move(int c);
	void print();
	void checkBounds();

private:
	
};

