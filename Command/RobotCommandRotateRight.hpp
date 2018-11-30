#pragma once

#include "RobotCommandBase.hpp"

#include <iostream>

struct RobotCommandRotateRight : RobotCommandBase
{
	RobotCommandRotateRight(Robot &i_robot) : RobotCommandBase(i_robot) {}
	
	virtual void move() const override final
	{
		std::cout << COMMAND_LOG_SCOPE;
		std::cout << "Doing rotate right command." << std::endl;
		robot.rotate_right();
	}
	virtual void undo() const override final
	{
		std::cout << COMMAND_LOG_SCOPE;
		std::cout << "Undoing rotate right command." << std::endl;
		robot.rotate_left();
	}
};
