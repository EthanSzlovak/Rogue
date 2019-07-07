#include "pch.h"
#include "Enemy.h"
#include "Object.h"
//This will be used for the infiltration missions
	Enemy::Enemy(int startX, int startY) {
		Object::xPos = startX;
		Object::yPos = startY;
	};

	//TODO: Implement AI enums and Systems
	//TEMPORARY FUNCTION

	void Enemy::_move(Object target) {
		//TODO: Implement A* Targeting System
		//Enemy Targets and Behaviours will depend on what type of AI (Chase will target player directly, stalk targets nearest point out of view of the player etc etc)
		//Move in that Direction
	}
