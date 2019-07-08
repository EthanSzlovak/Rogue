#pragma once
#include <curses.h>
#include <string>

using std::string;

class Object{
	public:
		//Object Destructor: DO NOT USE.
		virtual ~Object() = default;
	protected:
		double _xPos, _yPos, _spd;

		string name, description;
		int health;
		int dispRow, dispCol;
		//Movement Function for an Object
		virtual void _move() {};

		//Display Function for an object
		virtual void _print();

		virtual inline double getX();
		virtual inline double getY();
};