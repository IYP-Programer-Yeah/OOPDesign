#pragma once

#include <cstddef>
#include "Car.hpp"

struct Decorator : public Car
{
	Decorator(Car &i_car) : Car(i_car.hourse_power, i_car.fuel_tank_size), car(i_car){}

	virtual std::size_t cost() const override
	{
		return car.cost();
	}
private:
	Car &car;
};
