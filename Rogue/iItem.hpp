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
		
		int value_, weight_;
		string name_;

		enhanceType enhanceType_ = enhanceType::E_NONE;
		iType type_ = iType::NONE;
		


	public:
		void (*onConsumeWeapon_)( class iWeapon&);
		iItem() {
			name_ = " ";
			value_ = -1;
			weight_ = -1;
		}
		

		
		//Constructor
		iItem(const char* name, int value, int weight, iType itemType = iType::NONE) {
			name_ = name;
			value_ = value;
			weight_ = weight;

			if (itemType == iType::CONSUMEABLE) {
				throw std::invalid_argument::logic_error("No onConsume function defined for consumeable item " + name_);
			}type_ = itemType;
		
		}



		//Consumeables
		iItem(const char* name, int value, int weight, void(*onConsumeWeapon)(iWeapon& n) ) {
			name_ = name;
			value_ = value;
			weight_ = weight;
			type_ = WEAPON;
			enhanceType_ = E_WEAPON;
			onConsumeWeapon_ = onConsumeWeapon;
		}

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

		double calculateActualValue() {
			//TODO: Implement Value Things

			return value_;
		}
	};