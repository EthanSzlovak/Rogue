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
		virtual void move() {};
		virtual void draw() {};

		int& xLoc() { return xLoc_; };
		int xLoc() const { return xLoc_; };

		void xLoc(int i) { xLoc_ = i; };

		int& yLoc() { return yLoc_; };
		int yLoc() const { return yLoc_; };
		void yLoc(int i) { yLoc_ = i; };
	};
}