#pragma once

#include <cmath>

struct Triangle
{
	float surface(float x1, float x2, float x3, float y1, float y2, float y3) const
	{
		return std::abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2))/2;
	}
};
