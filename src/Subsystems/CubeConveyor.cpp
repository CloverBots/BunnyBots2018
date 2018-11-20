#include "CubeConveyor.h"
#include "../RobotMap.h"
#include "WPILib.h"

CubeConveyor::CubeConveyor() : Subsystem("CubeConveyorSubsystem") {
	Cube_Conveyor_Left = new Talon(RobotMap::Cube_Conveyor_Left);
	Cube_Conveyor_Right = new Talon(RobotMap::Cube_Conveyor_Right);
}

void CubeConveyor::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void CubeConveyor::SetSpeed(double speed)
{
	Cube_Conveyor_Left->Set(speed);
	Cube_Conveyor_Right->Set(speed);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
