#pragma once
#include "curses.h"
#include <vector>
#include <string>
#include "Location.hpp"
using std::vector;
using std::string;

namespace Rogue {
	class iObject {
	protected:
		
		int xLoc_, yLoc_, health_;
		char image_;
	public:
		
		iObject() {
			xLoc_ = 0;
			yLoc_ = 0;
			health_ = 10;
			image_ = ' ';
		};
		void move() {};
		// used for monster instances
		virtual void move(const int& pXLoc, const int& pYLoc) {}

		virtual void draw(WINDOW* w) {};
		

		void takeDamage(double damageToTake /*, DAMAGE TYPE?, DAMAGE SOURCE?*/);
		void updateState() {};
		int& xLoc() { return xLoc_; };
		int xLoc() const { return xLoc_; };

		int& yLoc() { return yLoc_; };
		int yLoc() const { return yLoc_; };
	};
}