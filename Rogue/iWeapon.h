#pragma once
#include "iItem.h"
class iWeapon : protected iItem{
protected:
	const int MIN_ENHANCEMENT{ -20 };
	int damage_, quality_, maxEnhancement_, currentEnhancement_;

public:

	iWeapon();
	int getQuality() { return quality_; };
	//Use for back-end calculations, actual damage is based on a variety of different factors
	int getDamage() { return damage_; };


	double getActualDamage(){
		double actualDamage = damage_;
		//TODO: Calculation for actual damage;
		return actualDamage;
	};

	void sumEnhancement(int toChangeBy) {
		currentEnhancement_ += toChangeBy;
		if (currentEnhancement_ > maxEnhancement_) {
			currentEnhancement_ = maxEnhancement_;
		}if (currentEnhancement_ < MIN_ENHANCEMENT) {
			currentEnhancement_ = MIN_ENHANCEMENT;
		}
	};

	string getName() {
		return name_;
	}
	//TODO Find way to add prefix and suffix, Incredible sword of Fire etc.
	void changeName(string toChange) {
		name_ = toChange;
	}




};

