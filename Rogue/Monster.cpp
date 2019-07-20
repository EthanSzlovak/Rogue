#include "Monster.h"
void Monster::move(const int& pXLoc, const int& pYLoc){
	int x_diff = pXLoc - xLoc_;
	int y_diff = pYLoc - yLoc_;

	int abs_x_diff = abs(x_diff);
	int abs_y_diff = abs(y_diff);

	// figure out whether x or y is closer
	if (abs_x_diff > abs_y_diff)
	{
		if (x_diff < 0)
			--xLoc_;
		else
			++xLoc_;
	}
	else
	{
		if (y_diff < 0)
			--yLoc_;
		else
			++yLoc_;
	}
}