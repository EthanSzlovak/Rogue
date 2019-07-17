#pragma once
virtual class Object {
	int xLoc_, yLoc_;
	char image_;
	virtual Object();
	virtual void move();
	virtual void draw();


};