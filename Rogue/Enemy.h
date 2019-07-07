#pragma once

//For use in the government infiltration missions
class Enemy :protected Object{

public:
private:
	Enemy(int, int);
	void _move(Object target);
};

