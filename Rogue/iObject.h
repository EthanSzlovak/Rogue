#pragma once
#include "curses.h"
#include <vector>
#include <string>
using std::vector;
using std::string;
static vector<string> inventory;
namespace Rogue {
	class iObject {
		
	protected:
		int xLoc_, yLoc_;
		char image_;
	public:
		
		iObject() {
			xLoc_ = 0;
			yLoc_ = 0;
			image_ = ' ';
		};
		void move() {};
		// used for monster instances
		virtual void move(const int& pXLoc, const int& pYLoc) {}

		virtual void draw(WINDOW* w) {};

		void updateState() {};
		int& xLoc() { return xLoc_; };
		int xLoc() const { return xLoc_; };

		int& yLoc() { return yLoc_; };
		int yLoc() const { return yLoc_; };
	};
}