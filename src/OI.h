/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <WPILib.h>
#pragma once

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
	bool GetAxis(int controller, Axis axis);
	bool GetButton(int controller, Buttons button);
	OI();
};
