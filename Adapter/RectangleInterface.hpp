#pragma once

struct RectangleInterface
{
	virtual float rect_surface(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4) const = 0;
};