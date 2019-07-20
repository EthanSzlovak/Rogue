#pragma once
#include "iObject.h"
#include <vector>
#include <iostream>

	

using std::string;
class Player : public Rogue::iObject{
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


	
	inline void move() {}
};

