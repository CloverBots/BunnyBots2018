#include "BallPickUp.h"
#include "../RobotMap.h"
#include "WPILib.h"
#include <ctre/Phoenix.h>

BallPickUp::BallPickUp() : Subsystem("BallPickUpSubsystem") {
	Ball_Pick_Up_Motor = new WPI_TalonSRX(RobotMap::Ball_Pick_Up_Motor);
}

void BallPickUp::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void BallPickUp::SetSpeed(double speed)
{
	Ball_Pick_Up_Motor->Set(speed);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
