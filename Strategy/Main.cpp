#include "TrafficLight.hpp"

int main()
{
	TrafficLight traffic_light;
	traffic_light.cycle();
	for (std::uint8_t h = 0; h < 24; h++)
	{
		traffic_light.update_policy(h, 0);
		traffic_light.cycle();
	}
	return 0;
}