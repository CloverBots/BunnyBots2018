#include "CubePickUp.h"
#include "../RobotMap.h"
#include "WPILib.h"
#include "Commands/CubePickUpCMD.h"

CubePickUp::CubePickUp() : Subsystem("CubePickUpSubsystem")
{
	Cube_Pick_Up_Left = new WPI_TalonSRX(RobotMap::Cube_Pick_Up_Left);
	Cube_Pick_Up_Right = new WPI_TalonSRX(RobotMap::Cube_Pick_Up_Right);

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
	Cube_Pick_Up_Left->Set(speed);
	Cube_Pick_Up_Right->Set(speed);
	if(speed != 0)
	{
		Grabber->Set(DoubleSolenoid::Value::kForward);
	}
	else
	{
		Grabber->Set(DoubleSolenoid::Value::kReverse);
	}
}

void CubePickUp::Grab(DoubleSolenoid::Value value)
{
	Grabber->Set(value);
}
