#pragma once
#include "iInterface.h"

template <class X, class Y>
class Pair {
	X x_;
	Y y_;

public:
	X getX() {
		return x_;
	}

	Y getY() {
		return y_;
	}

	Pair(X x, Y y) {
		x_ = x;
		y_ = y;
	}
}; 
