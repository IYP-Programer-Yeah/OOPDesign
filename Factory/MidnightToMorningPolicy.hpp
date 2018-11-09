#pragma once
#include "TrafficLightPolicy.hpp"
#include <iostream>

struct MidnightToMorningPolicy : public TrafficLightPolicy
{
	virtual void cycle() override final
	{
		std::cout << "Cycles are set by the midnight to morning policy." << std::endl;
	}
};