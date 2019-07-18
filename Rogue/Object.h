#pragma once
#include "curses.h"
namespace Rogue {
	class Object {
	protected:
		int xLoc_, yLoc_;
		char image_;
	public:
		Object() {
			xLoc_ = 0;
			yLoc_ = 0;
			image_ = ' ';
		};
		virtual void move() = 0;
		virtual void draw(WINDOW* w) = 0;

		int& xLoc() { return xLoc_; };
		int xLoc() const { return xLoc_; };


		int& yLoc() { return yLoc_; };
		int yLoc() const { return yLoc_; };
	};
}