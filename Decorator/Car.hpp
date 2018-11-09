#pragma once

#include <cstddef>

struct Car
{
	const std::size_t hourse_power;
	const std::size_t fuel_tank_size;

	virtual std::size_t cost() const = 0;

	Car(const std::size_t i_hourse_power, const std::size_t i_fuel_tank_size) : hourse_power(i_hourse_power), fuel_tank_size(i_fuel_tank_size) {}
};
