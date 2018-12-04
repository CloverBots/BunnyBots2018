#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int kLeftMotor = 1;
// constexpr int kRightMotor = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;

class RobotMap
{
public:
	const static unsigned int
		Front_Left_Motor = 5,
		Front_Right_Motor = 8,
		Middle_Left_Motor = 6,
		Middle_Right_Motor = 9,
		Back_Left_Motor = 7,
		Back_Right_Motor = 11,
		Cube_Pick_Up_Left = 1,
		Cube_Pick_Up_Right = 2,
		Cube_Conveyor_Left_1 = 3,
		Cube_Conveyor_Right_1 = 4,
		Cube_Conveyor_Left_2 = 10,
		Cube_Conveyor_Right_2 = 12,
		Ball_Pick_Up_Motor = 13,
		Ball_Conveyor_Motor = 14,
		Ball_Hopper_Motor = 15;
};
#endif // ROBOTMAP_H
