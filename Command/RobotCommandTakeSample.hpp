#pragma once

#include "RobotCommandBase.hpp"

#include <iostream>

struct RobotCommandTakeSample : RobotCommandBase
{
	RobotCommandTakeSample(Robot &i_robot) : RobotCommandBase(i_robot) {}

	virtual void move() const override final
	{
		std::cout << COMMAND_LOG_SCOPE;
		std::cout << "Doing take sample command." << std::endl;
		robot.take_sample();
	}
	virtual void undo() const override final
	{
		std::cout << COMMAND_LOG_SCOPE;
		std::cout << "Undoing take sample command." << std::endl;
		std::cerr << "Can't undo take sample." << std::endl;
	}
};
