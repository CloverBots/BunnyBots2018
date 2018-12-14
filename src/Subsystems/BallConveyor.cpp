#include "BallConveyor.h"
#include "../RobotMap.h"
#include "WPILib.h"
#include <ctre/Phoenix.h>
#include "Commands/BallConveyorCMD.h"

BallConveyor::BallConveyor() : Subsystem("BallConveyorSubsystem")
{
	Ball_Conveyor_Motor = new WPI_TalonSRX(RobotMap::Ball_Conveyor_Motor);
	Ball_Conveyor_Motor->ConfigOpenloopRamp(.25, 10);
}

void BallConveyor::InitDefaultCommand()
{
	SetDefaultCommand(new BallConveyorCMD());
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void BallConveyor::SetSpeed(double speed)
{
	Ball_Conveyor_Motor->Set(speed);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
