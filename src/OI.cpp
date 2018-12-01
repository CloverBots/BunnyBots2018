/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include <WPILib.h>
#include <Commands/BallConveyorCMD.h>
#include <Commands/BallPickUpCMD.h>
#include <Commands/CubeConveyorCMD.h>
#include <Commands/CubePickUpCMD.h>

OI::OI()
{
	team = DriverStation::Alliance::kInvalid;
	start_time = 0;
	end_time = 0;
	pDriveStick = new Joystick(0);
	pOperatorStick = new Joystick(1);
	DriverAButton = new JoystickButton(pOperatorStick, 1);
	DriverBButton = new JoystickButton(pOperatorStick, 2);
	DriverXButton = new JoystickButton(pOperatorStick, 3);
	DriverYButton = new JoystickButton(pOperatorStick, 4);
	DriverBackButton = new JoystickButton(pOperatorStick, 7);
	DriverStartButton = new JoystickButton(pOperatorStick, 8);
	DriverLBumperButton = new JoystickButton(pOperatorStick, 5);
	DriverRBumperButton = new JoystickButton(pOperatorStick, 6);
	DriverLJoyDownButton = new JoystickButton(pOperatorStick, 9);
	DriverRJoyDownButton = new JoystickButton(pOperatorStick, 10);
	OperatorAButton = new JoystickButton(pOperatorStick, 1);
	OperatorBButton = new JoystickButton(pOperatorStick, 2);
	OperatorXButton = new JoystickButton(pOperatorStick, 3);
	OperatorYButton = new JoystickButton(pOperatorStick, 4);
	OperatorBackButton = new JoystickButton(pOperatorStick, 7);
	OperatorStartButton = new JoystickButton(pOperatorStick, 8);
	OperatorLBumperButton = new JoystickButton(pOperatorStick, 5);
	OperatorRBumperButton = new JoystickButton(pOperatorStick, 6);
	OperatorLJoyDownButton = new JoystickButton(pOperatorStick, 9);
	OperatorRJoyDownButton = new JoystickButton(pOperatorStick, 10);

	// Process operator interface input here.
}

void OI::SetTeam(DriverStation::Alliance team)
{
	this->team = team;
}

DriverStation::Alliance OI::GetTeam()
{
	return team;
}

Joystick* OI::GetDriveStick()
{
	return pDriveStick;
}

double OI::GetAxis(int controller, Axis axis)
{
	if(controller == 0)
	{
		switch(axis)
		{
			case Axis::LeftUpDown:
				return pDriveStick->GetRawAxis(1);
				break;
			case Axis::RightUpDown:
				return pDriveStick->GetRawAxis(5);
				break;
			case Axis::LeftLeftRight:
				return pDriveStick->GetRawAxis(0);
				break;
			case Axis::RightLeftRight:
				return pDriveStick->GetRawAxis(4);
				break;
			case Axis::LeftTrigger:
				return pDriveStick->GetRawAxis(2);
				break;
			case Axis::RightTrigger:
				return pDriveStick->GetRawAxis(3);
				break;
			default:
				return false;
				break;
		}
	}
	else
	{
		switch(axis)
		{
			case Axis::LeftUpDown:
				return pOperatorStick->GetRawAxis(1);
				break;
			case Axis::RightUpDown:
				return pOperatorStick->GetRawAxis(5);
				break;
			case Axis::LeftLeftRight:
				return pOperatorStick->GetRawAxis(0);
				break;
			case Axis::RightLeftRight:
				return pOperatorStick->GetRawAxis(4);
				break;
			case Axis::LeftTrigger:
				return pOperatorStick->GetRawAxis(2);
				break;
			case Axis::RightTrigger:
				return pOperatorStick->GetRawAxis(3);
				break;
			default:
				return false;
				break;
		}
	}
}

bool OI::GetButton(int controller, Buttons button)
{
	if(controller == 0)
	{
		switch(button)
		{
			case Buttons::A:
				return DriverAButton->Get();
				break;
			case Buttons::B:
				return DriverBButton->Get();
				break;
			case Buttons::X:
				return DriverXButton->Get();
				break;
			case Buttons::Y:
				return DriverYButton->Get();
				break;
			case Buttons::Back:
				return DriverBackButton->Get();
				break;
			case Buttons::Start:
				return DriverStartButton->Get();
				break;
			case Buttons::LBumper:
				return DriverLBumperButton->Get();
				break;
			case Buttons::RBumper:
				return DriverRBumperButton->Get();
				break;
			case Buttons::LJoyDown:
				return DriverLJoyDownButton->Get();
				break;
			case Buttons::RJoyDown:
				return DriverRJoyDownButton->Get();
				break;
			default:
				return false;
				break;
		}
	}
	else
	{
		switch(button)
		{
			case Buttons::A:
				return OperatorAButton->Get();
				break;
			case Buttons::B:
				return OperatorBButton->Get();
				break;
			case Buttons::X:
				return OperatorXButton->Get();
				break;
			case Buttons::Y:
				return OperatorYButton->Get();
				break;
			case Buttons::Back:
				return OperatorBackButton->Get();
				break;
			case Buttons::Start:
				return OperatorStartButton->Get();
				break;
			case Buttons::LBumper:
				return OperatorLBumperButton->Get();
				break;
			case Buttons::RBumper:
				return OperatorRBumperButton->Get();
				break;
			case Buttons::LJoyDown:
				return OperatorLJoyDownButton->Get();
				break;
			case Buttons::RJoyDown:
				return OperatorRJoyDownButton->Get();
				break;
			default:
				return false;
				break;
		}
	}
}

int OI::GetDPad(int controller)
{
	if(controller == 0)
	{
		return pDriveStick->GetPOV(0);
	}
	else
	{
		return pOperatorStick->GetPOV(0);
	}
}
