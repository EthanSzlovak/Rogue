#pragma once
#include "Object.h"
#include <iostream>

class Player : public Rogue::Object{

public:
	Player(int xLoc, int yLoc) {
		xLoc_ = xLoc; 
		yLoc_ = yLoc;
		image_ = '@';
	}

	void move() override{
		int i = 0;
		while (i < 100) {
			std::cout << "APPLES" << std::endl;
			i++;
		}std::cout << "I am going to say the N world : Nearth." << std::endl;
	};

	void draw(WINDOW* w) {
		wmove(w, yLoc_, xLoc_);
		wprintw(w, &image_);
	}

	inline virtual void move() override { const bool moving = true; }
};

