#include "pch.h"
#include "Player.h"
#include "curses.h"
namespace curses{
	using ::move;
}



Player::~Player() {
}
void Player::_move(int c){ 
	/*
	switch (c) {
	case KEY_UP:
		if (mvinch(_xPos - 1, _yPos) != 'X') {
			this->_xPos--;
			this->_xPos--;
		}
		break;
	case KEY_DOWN:
		if (mvinch(_xPos + 1, _yPos) != 'X') {
			this->_xPos++;
		}
		break;
	case KEY_LEFT:
		if (mvinch(_xPos, _yPos - 1) != 'X') {
			_yPos--;
		}
		break;
	case KEY_RIGHT:
		if (mvinch(_xPos, _yPos + 1) != 'X') {
			_yPos++;
		}
		break;
	default:
		break;
	}
	curses::move(_xPos, _yPos);
	printw("@");
	*/
}