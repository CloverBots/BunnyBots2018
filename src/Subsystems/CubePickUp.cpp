#include "CubePickUp.h"
#include "../RobotMap.h"
#include "WPILib.h"

CubePickUp::CubePickUp() : Subsystem("CubePickUpSubsystem")
{
	Cube_Pick_Up_Left = new Talon(RobotMap::Cube_Pick_Up_Left);
	Cube_Pick_Up_Right = new Talon(RobotMap::Cube_Pick_Up_Right);
}

void CubePickUp::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void CubePickUp::SetSpeed(double speed)
{
	Cube_Pick_Up_Left->Set(speed);
	Cube_Pick_Up_Right->Set(speed);
}
