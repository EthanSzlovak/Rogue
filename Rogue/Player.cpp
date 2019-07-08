#include "pch.h"
#include "Player.h"
#include "curses.h"
namespace curses{
	using ::move;
}



Player::~Player() {
}
void Player::move(int c){ 
	
	switch (c) {
	case KEY_UP:
		if (mvinch(xPos - 1, yPos) != 'X') {
			this->xPos--;
			this->xPos--;
		}
		break;
	case KEY_DOWN:
		if (mvinch(xPos + 1, yPos) != 'X') {
			this->xPos++;
		}
		break;
	case KEY_LEFT:
		if (mvinch(xPos, yPos - 1) != 'X') {
			yPos--;
		}
		break;
	case KEY_RIGHT:
		if (mvinch(xPos, yPos + 1) != 'X') {
			yPos++;
		}
		break;
	default:
		break;
	}
	curses::move(xPos, yPos);
	printw("@");
}