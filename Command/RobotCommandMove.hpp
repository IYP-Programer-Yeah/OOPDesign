#pragma once

#include "RobotCommandBase.hpp"

struct RobotCommandMove : RobotCommandBase
{
	RobotCommandMove(Robot &i_robot) : RobotCommandBase(i_robot) {}

	virtual void move() const override final
	{
		std::cout << COMMAND_LOG_SCOPE;
		std::cout << "Doing move command." << std::endl;
		robot.move();
	}
	virtual void undo() const override final
	{
		std::cout << COMMAND_LOG_SCOPE;
		std::cout << "Undoing move command." << std::endl;
		robot.rotate_left();
		robot.rotate_left();
		robot.move();
		robot.rotate_left();
		robot.rotate_left();
	}
};
