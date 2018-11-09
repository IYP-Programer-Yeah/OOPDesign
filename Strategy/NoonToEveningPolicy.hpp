#pragma once
#include "TrafficLightPolicy.hpp"
#include <iostream>

struct NoonToEveningPolicy : public TrafficLightPolicy
{
	virtual void cycle() override final
	{
		std::cout << "Cycles are set by the noon to evening policy." << std::endl;
	}
};