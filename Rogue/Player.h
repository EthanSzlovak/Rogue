#pragma once
#include "iObject.h"
#include "iItem.hpp"
#include "iWeapon.h"

#include <vector>
#include <iostream>

	

using std::string;
class Player : public Rogue::iObject{
public:
	iItem rHand, lHand;

	Player(int xLoc, int yLoc) {
		xLoc_ = xLoc; 
		yLoc_ = yLoc;
		image_ = '@';
	}

	~Player() = default;
	
	void draw(WINDOW* w) {
		wmove(w, yLoc_, xLoc_);
		wprintw(w, &image_);
	}

	//TODO: Implement Items for the Inventory
	double getTotalInventoryWeight() {
		return 1;
	}
	
	inline void move() {}
};

