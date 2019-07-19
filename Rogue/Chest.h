#pragma once
#include "Object.h"
#include <string>
#include <iostream>
#include "Player.h"
using std::string;
class Chest : protected Rogue::Object {
private:

	bool isOpened = false;
	string inventory_ = "Delicious Treasure";
public: 

	Chest(string inventory, int xLoc, int yLoc) {
		xLoc_ = xLoc;
		yLoc_ = yLoc;
		inventory_ = inventory;
		image_ = 'O';
	}

	void draw(WINDOW* w) {
		wmove(w, yLoc_, xLoc_);
		wprintw(w, &image_);
	}

	void move() {

	}
	void updateState(WINDOW* w) {
		if (mvwinch(w, yLoc_, xLoc_) == '@'&&!isOpened) {
			isOpened = true;
			inventory.push_back(inventory_);
			inventory_ = "";
			image_ = '0';
			
		}
	}
	void setInventory(string toSet){inventory_ = toSet;}
	string getInventory() { return inventory_; };

};

