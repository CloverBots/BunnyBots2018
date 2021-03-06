/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "BallSort.h"
#include "../RobotMap.h"
#include "Commands/BallSortCMD.h"
#include <WPILib.h>
#include <iostream>

BallSort::BallSort() : Subsystem("ExampleSubsystem")
{
	red_value = 0;
	green_value = 0;
	blue_value = 0;

	solenoid = new Relay(0);
	solenoid->Set(Relay::Value::kForward);
	color_sensor = new I2C(frc::I2C::Port::kOnboard, 0x39);
	color_sensor->Write(COMMAND_REGISTER_BIT | ENABLE_REGISTER, 0b00000011);
	color_sensor->Write(COMMAND_REGISTER_BIT | ATIME_REGISTER, 0xFF);
}

void BallSort::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new BallSortCMD());
}


void BallSort::SetSolenoid(Relay::Value value)
{
	solenoid->Set(value);
}

void BallSort::UpdateSensor()
{
	color_sensor->Read(COMMAND_REGISTER_BIT | MULTI_BYTE_BIT | RDATA_REGISTER, 6, data);
	red_value = data[0];
	green_value = data[2];
	blue_value = data[4];
	//std::cout << "RED: " << (int)red_value << "  BLUE: " << (int)blue_value << std::endl;
}

bool BallSort::IsRed()
{
	return ((int)red_value >= 12 && (int)red_value <= 255 && (int)blue_value < 12);
}

bool BallSort::IsBlue()
{
	return ((int)blue_value >= 12 && (int)blue_value <= 255 && (int)red_value < 12);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
