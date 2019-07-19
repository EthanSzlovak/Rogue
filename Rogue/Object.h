#pragma once
#include "curses.h"
#include <vector>
#include <string>
using std::vector;
using std::string;
static vector<string> inventory;
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
		void move() {};

		void draw(WINDOW* w) {};

		void updateState() {};
		int& xLoc() { return xLoc_; };
		int xLoc() const { return xLoc_; };


		int& yLoc() { return yLoc_; };
		int yLoc() const { return yLoc_; };
	};
}