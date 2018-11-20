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
		Front_Left_Motor = 0,
		Front_Right_Motor = 1,
		Middle_Left_Motor = 2,
		Middle_Right_Motor = 3,
		Back_Left_Motor = 4,
		Back_Right_Motor = 5,
		Cube_Pick_Up_Left = 6,
		Cube_Pick_Up_Right = 7,
		Cube_Conveyor_Left = 8,
		Cube_Conveyor_Right = 9,
		Ball_Pick_Up_Motor = 10,
		Ball_Conveyor_Motor = 11;
};
#endif // ROBOTMAP_H
