#pragma once
#include "iObject.h"

using namespace Rogue;

class Monster : public iObject{
public:
	// each monster needs initial position
	Monster() = delete;
	~Monster() = default;	

	Monster(int xLoc, int yLoc, char img) {
		xLoc_ = xLoc;
		yLoc_ = yLoc;
		image_ = img;
	}

	void draw(WINDOW* w) override {
		wmove(w, yLoc_, xLoc_);
		wprintw(w, &image_);
	}

	void takeDamage(double damageToTake) {

	}
	void move() {}

	void move(const int& pXLoc, const int& pYLoc) override;

protected:


private:
	int abs(const int& x)
	{
		if (x < 0)
			return x * -1;
		else
			return x;
	}

};

