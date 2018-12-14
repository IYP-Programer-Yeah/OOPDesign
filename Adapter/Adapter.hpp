#pragma once

#include "RectangleInterface.hpp"
#include "Triangle.hpp"

struct Adapter : public RectangleInterface, private Triangle
{
	virtual float rect_surface(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4) const override final
	{
		return surface(x1, x2, x3, y1, y2, y3) + surface(x2, x3, x4, y2, y3, y4);
	}
};
