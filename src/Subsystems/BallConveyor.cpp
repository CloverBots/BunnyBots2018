#include "BallConveyor.h"
#include "../RobotMap.h"
#include "WPILib.h"

BallConveyor::BallConveyor() : Subsystem("BallConveyorSubsystem") {
	Ball_Conveyor_Motor = new Talon(RobotMap::Ball_Conveyor_Motor);
}

void BallConveyor::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void BallConveyor::SetSpeed(double speed)
{
	Ball_Conveyor_Motor->Set(speed);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
