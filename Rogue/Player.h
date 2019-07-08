#pragma once
#include "Object.h"
#include "Array.hpp"
#include <curses.h>

using gameBits::Array;
class Player : public Object{
public:
	Player(int xPos, int yPos){

		dishInventorySize = 1;
		obje = new Array<Object>(1);
		
		yPos = 0;
	};
	//Player(int row = 0, int col = 0) {};


	~Player();
	void _move(int c);
	void _print();

private:
	int dishInventorySize;
	gameBits::Array<Object>* obje;
	
};

