#pragma once
#include <string>
#include <iostream>
#include <exception>
#include <functional>
using std::string;
using std::function;


	enum iType {
		NONE = -1,
		WEAPON = 0,
		CONSUMEABLE = 1,
		WEARABLE = 2,
		MATERIAL = 3
	};
	enum enhanceType {
		E_NONE = -1,
		E_WEAPON = 0,
		E_STAT = 1
	};

	class iItem {

	protected:
		
		int value_, weight_, quality_, durability_ = -1;
		string name_;

		enhanceType enhanceType_ = enhanceType::E_NONE;
		iType type_ = iType::NONE;
		


	public:
		void (*onConsumeWeapon_)( class iWeapon&);

		//Empty Constructor
		iItem() {
			name_ = " ";
			value_ = -1;
			weight_ = -1;
			quality_ = -1;
		}
		
		//Normal Constructor
		iItem(const string& name, int value, int weight, iType itemType = iType::NONE);

		//Weapon Consumeables (Whetstone, enhancers, etc)
		iItem(const string& name, int value, int weight, void(*onConsumeWeapon)(iWeapon& n), int durability = 1, int quality = 0);

		~iItem() = default;

		//Copy Constructors
		inline iItem(const iItem& copy) noexcept(false) {
			*this = copy;
		}

		iItem& operator=(const iItem& rhs) {
			name_ = rhs.name_;
			value_ = rhs.value_;
			weight_ = rhs.weight_;
			return *this;
		}

		//Move Constructors
		inline iItem(iItem&& copy) noexcept(false) {
			*this = std::move(copy);
		}

		iItem& operator=(iItem&& rhs) noexcept(false) {
			name_ = std::move(rhs.name_);
			value_ = std::move(rhs.value_);
			weight_ = std::move(rhs.weight_);
			return *this;
		}


		//Getters and Setters
		inline string& Name() { return name_; }
		inline string Name() const { return name_; }

		inline int& Value() { return value_; }
		inline int Value() const { return value_; }

		inline int& Weight() { return weight_; }
		inline int Weight() const { return weight_; };
		
		inline int& Quality() { return quality_; }
		inline int Quality() const {return quality_;}

		double calculateActualValue() {
			//TODO: Implement Value Things

			return value_;
		}
	};

	iItem::iItem(const string& name, int value, int weight, iType itemType = iType::NONE) {
		name_ = name;
		value_ = value;
		weight_ = weight;
		quality_ = 0;
		durability_ = 0;
		if (itemType == iType::CONSUMEABLE) {
			throw std::invalid_argument::logic_error("No onConsume function defined for consumeable item " + name_);
		}type_ = itemType;
	}


	iItem::iItem(const string& name, int value, int weight, void(*onConsumeWeapon)(iWeapon& n), int durability = 1, int quality = 0) {
		name_ = name;
		value_ = value;
		weight_ = weight;
		type_ = WEAPON;
		enhanceType_ = E_WEAPON;
		quality_ = quality_;
		durability_ = durability;
		onConsumeWeapon_ = onConsumeWeapon;
	}