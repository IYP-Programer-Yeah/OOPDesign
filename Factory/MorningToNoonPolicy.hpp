#pragma once
#include "TrafficLightPolicy.hpp"
#include <iostream>

struct MorningToNoonPolicy : public TrafficLightPolicy
{
	virtual void cycle() override final
	{
		std::cout << "Cycles are set by the morning to noon policy." << std::endl;
	}
};