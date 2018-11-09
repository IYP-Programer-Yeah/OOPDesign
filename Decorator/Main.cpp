#include "ABS.hpp"
#include "Airbag.hpp"
#include "CDPlayer.hpp"
#include "Coupe.hpp"
#include "Hatchback.hpp"
#include "LeatherInterior.hpp"
#include "Refrigerator.hpp"
#include "SUV.hpp"
#include "Sedan.hpp"
#include "Metalic.hpp"

#include <iostream>

void print_price(const char* const name, const Car& car)
{
	std::cout << name << " is priced at: " << car.cost() << std::endl;
}

int main()
{
	print_price("Metalic sedan with CD player", Metalic(200, CDPlayer(100, Sedan(1000, 200, 40))));
	return 0;
}
