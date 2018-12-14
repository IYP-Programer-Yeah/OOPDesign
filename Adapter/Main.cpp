#include "Adapter.hpp"
#include "RectangleInterface.hpp"

#include <iostream>

int main()
{
	Adapter a;
	RectangleInterface &rect = a;

	std::cout << rect.rect_surface(0, 1, 1, 0, 0, 0, 1, 1);
	return 0;
}