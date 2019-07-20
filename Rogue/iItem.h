#pragma once
#include <string>
#include <iostream>
using std::string;
class iItem{
protected:
	int value_, weight_;
	string name_;


	const bool CONSUMABLE{ false }, MATERIAL{ false }, WEAPON{ false };
public:
	
	//There should be no cases where this is used.
	iItem() = delete;

	//Constructor
	iItem(string name, int value, int weight) {
		name_ = name;
		value_ = value;
		weight_ = weight;
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
	inline iItem(iItem&& copy) noexcept(false){
		*this = std::move(copy);
	}

	iItem& operator=(iItem&& rhs) noexcept(false){
		name_ = std::move(rhs.name_);
		value_ = std::move(rhs.value_);
		weight_ = std::move(rhs.weight_);
		return *this;
	}


	//Getters and Setters
	inline string& Name() {return name_;}
	inline string Name() const { return name_; }
	
	inline int& Value() {return value_;}
	inline int Value() const { return value_; }

	inline int& Weight() { return weight_; }
	inline int Weight() const{ return weight_; };
	
	double calculateActualValue() {
		//TODO: Implement Value Things

		return value_;
	}
};

