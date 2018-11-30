#include "Robot.hpp"
#include "RobotCommandMove.hpp"
#include "RobotCommandRotateLeft.hpp"
#include "RobotCommandRotateRight.hpp"
#include "RobotCommandTakeSample.hpp"
#include "RobotController.hpp"

int main()
{
	Robot robot;

	RobotController controller;

	RobotCommandMove move_command(robot);
	RobotCommandRotateLeft rotate_left_command(robot);
	RobotCommandRotateRight rotate_right_command(robot);
	RobotCommandTakeSample take_sample(robot);

	controller.execute_command(move_command);
	controller.execute_command(move_command);
	controller.execute_command(rotate_left_command);
	controller.execute_command(move_command);
	controller.execute_command(move_command);
	controller.execute_command(rotate_right_command);
	controller.execute_command(move_command);
	controller.execute_command(move_command);
	controller.execute_command(take_sample);
	controller.execute_command(move_command);
	controller.undo_commands(4);
	controller.execute_command(move_command);
	controller.execute_command(move_command);
	controller.execute_command(rotate_left_command);
	controller.execute_command(move_command);
	controller.undo_commands(20);

	return 0;
}
