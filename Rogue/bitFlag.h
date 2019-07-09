#pragma once
#include <cmath>
#include <exception>
class bitFlag{
public:
	struct bitFlagException : public std::exception {
		const char* negativeIndex() const throw(){
			return "Error, Negative Index Specified in bitFlag";
		}

		const char* outOfBoundsIndex() const throw() {
			return "Error: Index out of bounds in bitFlag";
		}
	};

	bitFlag(double flagLength) {
		if (flagLength < 0) {
			throw bitFlagException().negativeIndex();
		}
		_fListing = new char[(ceil(flagLength / 8.))];
		
		_flagLength = ceil(flagLength / 8.);
		for (int i = 0; i < _flagLength; i++) {
			(_fListing[i]) = '\0';
		}
	}


	~bitFlag() { delete[] _fListing; }
	bool isFlagSet(double locToCheck) { 
		if (locToCheck < 0) {
			throw bitFlagException().negativeIndex();
		}if (locToCheck > _flagLength) {
			throw bitFlagException().outOfBoundsIndex();
		}
		return false;
	}
	void toggleFlag(int flagPos) {
		if (flagPos < 0) {
			throw bitFlagException().negativeIndex();
		}if (flagPos > _flagLength) {
			throw bitFlagException().outOfBoundsIndex();
		}



	}
	
	size_t getLength() { return _flagLength; };
private:
	int _flagLength;
	char* _fListing;
};
