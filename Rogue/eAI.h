#pragma once
#include "Object.h"
#include "Enemy.h"
class eAI : private Enemy{
protected: 
	enum TYPE {
		CHASE, FLEE, STALK, PASSIVE
	};

public:
	void Chase(Object toChase) {

	}
};

