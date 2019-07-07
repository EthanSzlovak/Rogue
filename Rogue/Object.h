#pragma once
class Object{
	public:
		Object();
		~Object();
	protected:
		double trow, tcol, spd = 2;


		int health;
		int dispRow, dispCol;

		void move(int c);
		void print();
};

