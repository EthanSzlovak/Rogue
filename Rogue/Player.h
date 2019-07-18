#pragma once
#include "Object.h"

class Player : public Rogue::Object{

public:
	Player(int xLoc, int yLoc) {
		xLoc_ = xLoc; 
		yLoc_ = yLoc;
		image_ = '@';
	}


	void draw(WINDOW* w) {
		wmove(w, yLoc_, xLoc_);
		wprintw(w, &image_);
	}

	inline virtual void move() override { const bool moving = true; }
	inline virtual void draw() override {}
};

