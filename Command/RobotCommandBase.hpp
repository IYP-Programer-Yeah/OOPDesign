#pragma once

#include "Robot.hpp"

struct RobotCommandBase
{
	RobotCommandBase(Robot &i_robot) : robot(i_robot){}
	virtual void move() const = 0;
	virtual void undo() const = 0;

protected:
	Robot &robot;
};
