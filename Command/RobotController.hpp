#pragma once

#include "RobotCommandBase.hpp"

#include <list>
#include <iostream>

struct RobotController
{
	void execute_command(const RobotCommandBase& command)
	{
		std::cout << "Executing command." << std::endl;
		command.move();
		commands.emplace_back(&command);
	}

	void undo_commands(std::size_t n)
	{
		std::cout << "Undoing last "<< n <<" commands." << std::endl;
		while (n && commands.begin() != commands.end())
		{
			commands.back()->undo();
			commands.pop_back();
			n--;
		}
	}

private:
	std::list<const RobotCommandBase*> commands;
};

