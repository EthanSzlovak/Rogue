#pragma once
#include "iItem.hpp"

class iWeapon : protected iItem{
protected:
	const int MIN_ENHANCEMENT{ -20 };
	int damage_, quality_, maxEnhancement_, currentEnhancement_;

public:

	iWeapon() = delete;
	//Constructor
	//name, value, weight, damage, quality, Maximum Enhancement, current enhancement
	iWeapon(const string& name, const int& value, const int& weight,
		const int& damage, const int& quality, const int& durability, 
		const int& maxEnhancement, const int& currentEnhancement) 
			: iItem(name, value, weight, WEAPON){
		damage_ = damage;
		quality_ = quality;
		maxEnhancement_ = maxEnhancement;
		currentEnhancement_ = currentEnhancement;
	}//name, value, weight, damage, quality, Maximum Enhancement, current enhancement

	//Getters and Setters
	using iItem::Name;
	using iItem::Value;
	using iItem::Weight;
	using iItem::Quality;

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

	//TODO Find way to add prefix and suffix, Incredible sword of Fire etc.
	int getEnhancement() {
		return this->currentEnhancement_;
	}
};

