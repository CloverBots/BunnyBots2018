/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <WPILib.h>
#pragma once
#include <chrono>

enum Axis
{
	LeftUpDown,
	RightUpDown,
	LeftLeftRight,
	RightLeftRight,
	LeftTrigger,
	RightTrigger
};

enum Buttons
{
	A,
	B,
	X,
	Y,
	Back,
	Start,
	LBumper,
	RBumper,
	LJoyDown,
	RJoyDown
};

class OI {
public:

	DriverStation::Alliance team;

	int total_ball_count = 0;
	int in_cube_ball_count = 0;

	std::chrono::system_clock::time_point start_time;
	std::chrono::system_clock::time_point end_time;
	int start = 0;
	int end = 0;

	int ball_threshold = 1;

	bool reset = false;
	bool in_zone_1 = false;
	bool throw_cube = false;
	bool throw_latch = false;

	Joystick* pDriveStick;
	Joystick* pOperatorStick;
	JoystickButton* DriverAButton;
	JoystickButton* DriverBButton;
	JoystickButton* DriverXButton;
	JoystickButton* DriverYButton;
	JoystickButton* DriverBackButton;
	JoystickButton* DriverStartButton;
	JoystickButton* DriverLBumperButton;
	JoystickButton* DriverRBumperButton;
	JoystickButton* DriverLJoyDownButton;
	JoystickButton* DriverRJoyDownButton;

	JoystickButton* OperatorAButton;
	JoystickButton* OperatorBButton;
	JoystickButton* OperatorXButton;
	JoystickButton* OperatorYButton;
	JoystickButton* OperatorBackButton;
	JoystickButton* OperatorStartButton;
	JoystickButton* OperatorLBumperButton;
	JoystickButton* OperatorRBumperButton;
	JoystickButton* OperatorLJoyDownButton;
	JoystickButton* OperatorRJoyDownButton;

	Joystick* GetDriveStick();
	double GetAxis(int controller, Axis axis);
	bool GetButton(int controller, Buttons button);
	int GetDPad(int controller);
	void SetTeam(std::string team);
	DriverStation::Alliance GetTeam();
	OI();
};
