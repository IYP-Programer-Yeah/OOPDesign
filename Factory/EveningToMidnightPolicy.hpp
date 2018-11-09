#pragma once
#include "TrafficLightPolicy.hpp"
#include <iostream>

struct EveningToMidnightPolicy : public TrafficLightPolicy
{
	virtual void cycle() override final
	{
		std::cout << "Cycles are set by the evening to midnight policy." << std::endl;
	}
};