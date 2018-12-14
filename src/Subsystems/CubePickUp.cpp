#include "CubePickUp.h"
#include "../RobotMap.h"
#include "WPILib.h"
#include <sys/time.h>
#include <chrono>
#include <thread>
#include <iostream>
#include "Commands/CubePickUpCMD.h"

CubePickUp::CubePickUp() : Subsystem("CubePickUpSubsystem")
{
	Cube_Pick_Up_Left = new WPI_TalonSRX(RobotMap::Cube_Pick_Up_Left);
	Cube_Pick_Up_Right = new WPI_TalonSRX(RobotMap::Cube_Pick_Up_Right);
	Grabber_Sensor = new DigitalInput(3);
	Grabber = new DoubleSolenoid(2,3);
}

void CubePickUp::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new CubePickUpCMD());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void CubePickUp::SetSpeed(double speed)
{
	Cube_Pick_Up_Left->Set(-speed);
	Cube_Pick_Up_Right->Set(speed);
}

bool CubePickUp::GetSensor()
{
	return !Grabber_Sensor->Get();
}

void CubePickUp::Grab(DoubleSolenoid::Value value)
{
	Grabber->Set(value);
}
