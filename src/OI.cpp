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

OI::OI() {
	pDriveStick = new Joystick(0);
		pOperatorStick = new Joystick(1);
		AButton = new JoystickButton(pOperatorStick, 1);
		BButton = new JoystickButton(pOperatorStick, 2);
		XButton = new JoystickButton(pOperatorStick, 3);
		YButton = new JoystickButton(pOperatorStick, 4);
		AButton->WhenPressed(new CubePickUpCMD(1));
		BButton->WhenPressed(new BallPickUpCMD(1));
		XButton->WhenPressed(new CubeConveyorCMD(1));
		YButton->WhenPressed(new BallConveyorCMD(1));
	// Process operator interface input here.
}
Joystick* OI::GetDriveStick()
{
	return pDriveStick;
}
