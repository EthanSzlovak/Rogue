#pragma once
#include "iObject.h"
#include "iInventory.h"
#include <string>
#include <iostream>
#include "Player.h"
using std::string;
class Chest : protected Rogue::iObject {
private:

	bool isOpened = false;
	iItem* inventory_ = nullptr;
public:
	Chest(const iItem& inventory, const int& xLoc,const int& yLoc) {
		xLoc_ = xLoc;
		yLoc_ = yLoc;
		try {
			inventory_ = new iItem(inventory);
			//inventory_ = iItem::rollNewItem();
		}
		catch (const std::bad_alloc& exception) {
			throw exception.what();
		}
		image_ = 'O';
	}

	~Chest() {
		delete inventory_;
	}
	//Standard Draw Method
	void draw(WINDOW* w) {
		wmove(w, yLoc_, xLoc_);
		wprintw(w, &image_);
	}

	//Updates state of chest in order to check if it is used
	void updateState(WINDOW* w) {
		if (mvwinch(w, yLoc_, xLoc_) == '@' && !isOpened) {
			isOpened = true;
			inventory.push_back(*inventory_);
			delete inventory_;
			image_ = '0';
		}
	};

	void move() {}


	inline void setInventory(iItem toSet) { 
		delete inventory_;
		inventory_ = nullptr;
		*inventory_ = std::move(toSet);
	}
	inline string getInventory() { return inventory_->Name(); };

};

