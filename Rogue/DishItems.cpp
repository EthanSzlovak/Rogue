#include "pch.h"
#include "DishItems.h"
#include <cmath>


DishItems::DishItems(double stick = 1, double oil = 1, double heat = 1, double hardness = 1, double starchiness = 1, double fluidity = 1, double dropChance = 1, double power = 1, double soakValue = 1, bool isParticulate = false, bool isConglomerate = false) {
	_stickiness = stick;
	_oilyness = oil;
	_heat = heat;
	_hardness = hardness;
	_isConglomerate = isConglomerate;
	_isParticulate = isParticulate;
	_power = std::fmin(std::fmax(power, 0.5), 4);
	_soakValue = soakValue;
	_starchiness = starchiness;
	_dropChance = dropChance;
	_fluidity = fluidity;
}

double DishItems::getScrubModifier() {
	return (pow(_stickiness, _power) / _fluidity) * (pow(_hardness, _power));
}

double DishItems::getGrindModifier() {
	return pow((_hardness * 10) - (0.15 * _heat), _power) * (pow(_stickiness, .5 * _power)) * (pow(1 / _fluidity, 0.75/_power));
}