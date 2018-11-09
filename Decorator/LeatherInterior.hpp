#pragma once

#include <cstddef>
#include "Decorator.hpp"

struct LetherInterior : public Decorator
{
	LetherInterior(const std::size_t i_additional_cost, Car &i_car) : Decorator(i_car), additional_cost(i_additional_cost) {}

	virtual std::size_t cost() const override final
	{
		return Decorator::cost() + additional_cost;
	}
private:
	const std::size_t additional_cost;
};
