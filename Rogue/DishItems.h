#pragma once
class DishItems {
private:
	 
	//Property Doubles
	double _stickiness, _oilyness, _heat, _hardness, _starchiness, _fluidity;

	//Game Doubles
	double _dropChance, _power, _soakValue;
	bool _isParticulate, _isConglomerate;
public:
	DishItems(double, double, double, double, double, double, double, double, double, bool, bool);
	double getScrubModifier(), getSprayModifier(), getHeatModifier(), getGrindModifier(), getSoakModifier();
};

