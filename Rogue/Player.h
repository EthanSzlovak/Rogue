#pragma once
#include "Object.h"
#include "Array.hpp"
#include <curses.h>
class Player : public Object{
public:
	Player() {
		xPos = 0;
		yPos = 0;
	};
	//Player(int row = 0, int col = 0) {};


	~Player();
	void move(int c);
	void print();
	void checkBounds();

private:
	Array<Object> pInventory;
};

