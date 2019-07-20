#pragma once
#include "iObject.h"

using namespace Rogue;

class Monster : public iObject
{
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

	void move() {}

	void move(const int& pXLoc, const int& pYLoc) override {
		int x_diff = pXLoc - xLoc_;
		int y_diff = pYLoc - yLoc_;

		int abs_x_diff = abs(x_diff);
		int abs_y_diff = abs(y_diff);

		// figure out whether x or y is closer
		if (abs_x_diff > abs_y_diff)
		{
			if (x_diff < 0)
				--xLoc_;
			else
				++xLoc_;
		}
		else
		{
			if (y_diff < 0)
				--yLoc_;
			else
				++yLoc_;
		}
	}

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

