#pragma once

#include <utility>
#include <cinttypes>
#include <list>
#include <iostream>

constexpr char ROBOT_LOG_SCOPE[] = "\t\t";
constexpr char COMMAND_LOG_SCOPE[] = "\t";

struct Robot
{
	Robot() : location(0, 0), direction(0, 1) {}

	void move()
	{
		std::cout << ROBOT_LOG_SCOPE;
		std::cout << "Moving in direction: (" << direction.first << ", " << direction.second << ") from location: (" << location.first << ", " << location.second << ") to location: (";

		location.first += direction.first;
		location.second += direction.second;

		std::cout << location.first << ", " << location.second << ")" << std::endl;
	}

	void rotate_left()
	{
		std::cout << ROBOT_LOG_SCOPE;
		const std::int64_t first = direction.first;

		std::cout << "Rrotating left from direction: (" << direction.first << ", " << direction.second << ") to direction: (";

		direction.first = -direction.second;
		direction.second = first;

		std::cout << direction.first << ", " << direction.second << ")" << std::endl;
	}

	void rotate_right()
	{
		std::cout << ROBOT_LOG_SCOPE;
		const std::int64_t first = direction.first;

		std::cout << "Rotating left from direction: (" << direction.first << ", " << direction.second << ") to direction: (";

		direction.first = direction.second;
		direction.second = -first;

		std::cout << direction.first << ", " << direction.second << ")" << std::endl;
	}

	void take_sample()
	{
		std::cout << ROBOT_LOG_SCOPE;
		std::cout << "Taking sample." << std::endl;
		samples.emplace_back(location, direction);
	}
private:
	using Point = std::pair<std::int64_t, std::int64_t>;
	using Vector = std::pair<std::int64_t, std::int64_t>;
	Point location;
	Vector direction;

	std::list<std::pair<Point, Vector>> samples;
};
