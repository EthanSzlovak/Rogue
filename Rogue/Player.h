#pragma once
#include "Object.h"
#include <vector>
#include <iostream>
static std::vector<std::string> inventory;

using std::string;
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


	static void addToInventory(string n) {
		inventory.push_back(n);
	}
	inline void move() {}
};

