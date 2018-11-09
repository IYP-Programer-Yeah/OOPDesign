#pragma once
#include "TrafficLightPolicy.hpp"
#include "MidnightToMorningPolicy.hpp"
#include "MorningToNoonPolicy.hpp"
#include "NoonToEveningPolicy.hpp"
#include "EveningToMidnightPolicy.hpp"

#include <cstdint>
#include <utility>
#include <iostream>

struct TrafficLight
{
	TrafficLight() {}

	TrafficLight(const std::uint8_t initial_h, const std::uint8_t initial_m)
	{
		update_policy(initial_h, initial_m);
	}

	TrafficLight(const TrafficLight&) = delete;

	TrafficLight& operator =(const TrafficLight&) = delete;

	TrafficLight(TrafficLight&& that)
	{
		policy = that.policy;
		that.policy = nullptr;
	}

	TrafficLight& operator = (TrafficLight&& that)
	{
		policy = that.policy;
		that.policy = nullptr;
		return *this;
	}

	void update_policy(const std::uint8_t h, const std::uint8_t m)
	{
		const TrafficLightPolicy *ex_policy = policy;

		const std::uint32_t time = get_time(h, m);
		if (time < get_time(6, 0)) // midnight to morning policy
			policy = new MidnightToMorningPolicy();
		else if (time < get_time(12, 0)) // morning to noon policy
			policy = new MorningToNoonPolicy();
		else if (time < get_time(18, 0)) // noon to evening policy
			policy = new NoonToEveningPolicy();
		else // evening to midnight policy
			policy = new EveningToMidnightPolicy();

		delete ex_policy;
	}

	void cycle()
	{
		if (policy == nullptr)
		{
			std::cout << "Invalid policy, update policy first." << std::endl;
			return;
		}
		policy->cycle();
	}

	~TrafficLight()
	{
		delete policy;
	}

private:
	static std::uint32_t get_time(std::uint8_t hour, std::uint8_t minute)
	{
		return (std::uint32_t(hour) * 60 + std::uint32_t(minute)) % (24*60); // avoid exceeding one day
	}

	TrafficLightPolicy *policy = nullptr;
};
