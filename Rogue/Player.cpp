#include "pch.h"
#include "Player.h"
#include "curses.h"
namespace curses{
	using ::move;
}



Player::~Player(){
}
void Player::move(int c){ 
	
	switch (c) {
	case KEY_UP:
		if (mvinch(trow - 1, tcol) != 'X') {
			this->trow--;
		}
		break;
	case KEY_DOWN:
		if (mvinch(trow + 1, tcol) != 'X') {
			this->trow++;
		}
		break;
	case KEY_LEFT:
		if (mvinch(trow, tcol - 1) != 'X') {
			tcol--;
		}
		break;
	case KEY_RIGHT:
		if (mvinch(trow, tcol + 1) != 'X') {
			tcol++;
		}
		break;
	default:
		break;
	}
	curses::move(trow, tcol);
	printw("@");
}