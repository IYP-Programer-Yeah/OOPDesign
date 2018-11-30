#pragma once

#include "RobotCommandBase.hpp"

struct RobotCommandRotateLeft : RobotCommandBase
{
	RobotCommandRotateLeft(Robot &i_robot) : RobotCommandBase(i_robot) {}

	virtual void move() const override final
	{
		std::cout << COMMAND_LOG_SCOPE;
		std::cout << "Doing rotate left command." << std::endl;
		robot.rotate_left();
	}
	virtual void undo() const override final
	{
		std::cout << COMMAND_LOG_SCOPE;
		std::cout << "Undoing rotate left command." << std::endl;
		robot.rotate_right();
	}
};
