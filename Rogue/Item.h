#pragma once
#include <string>
#include <iostream>
using std::string;
class Item{
protected:
	int value_, weight_;
	string name_;
public:
	//Constructor
	Item(string name, int value, int weight) {
		name_ = name;
		value_ = value;
		weight_ = weight;
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

