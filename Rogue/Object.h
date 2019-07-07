#pragma once
#include <curses.h>
#include <string>

using std::string;
class Object{
	public:

		//Object Constructor: DO NOT USE.
		Object() {};
		//Object Destructor: DO NOT USE.
		~Object() {};
	protected:
		double xPos, yPos, spd = 2;

		string name, description;
		int health;
		int dispRow, dispCol;
		//Movement Function for an Object
		virtual void _move() {};

		//Display Function for an object
		virtual void _print() {
			move(xPos, yPos);
			printw("No Entity Specified HELP ME");
		}

		inline double getX() { return this->xPos; }
		inline double getY() { return this->yPos; }
};

