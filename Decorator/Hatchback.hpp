#pragma once

#include <cstddef>
#include "Car.hpp"

struct Hatchback : public Car
{
	Hatchback(const std::size_t i_base_cost, const std::size_t i_hourse_power, const std::size_t i_fuel_tank_size) : Car(i_hourse_power, i_fuel_tank_size), base_cost(i_base_cost) {}

	virtual std::size_t cost() const override final
	{
		return base_cost;
	}
private:

	const std::size_t base_cost;
};
