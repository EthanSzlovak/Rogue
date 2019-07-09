#pragma once
#include "Object.h"
class Dish : protected Object {
public:

private:
	//TODO: Custom storage area where you can have plates up to a depth of n, where n is upgradeable over time
	/**TODO: Add inventory of stuff that makes the plates dirty, different objects have different modifiers for cleanup based on material used to clean
	
		Example: Oily type objects (Oil, Grease, Burned Carbon) are weak against soap and very weak against degreaser, but are strong against spraying off.
		Example: Sticky type objects (Caramelized Sugar, Syrup, etc.) are weak against hot liquid, but very strong against scrubbing and immune to degreaser.
		Example: Film type objects (Carbon Residue, Soot, etc.) are weak against scrubbing, but very strong against everything else.
	
	*/
	
	int width, height, depth;

};

