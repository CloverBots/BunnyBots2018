#include "DriveSub.h"
#include "../RobotMap.h"
#include <WPILib.h>
#include "DriveSub.h"

DriveSub::DriveSub() : Subsystem("driveSubsystem") {
	Front_Left_Motor = new Talon(RobotMap::Front_Left_Motor);
	Front_Right_Motor = new Talon(RobotMap::Front_Right_Motor);
	Middle_Left_Motor = new Talon(RobotMap::Middle_Left_Motor);
	Middle_Right_Motor = new Talon(RobotMap::Middle_Right_Motor);
	Back_Left_Motor = new Talon(RobotMap::Back_Left_Motor);
	Back_Right_Motor = new Talon(RobotMap::Back_Right_Motor);
	Gear_Box = new DoubleSolenoid(1, 2);
}

void DriveSub::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void DriveSub::Drive(double speed, double turn)
{
	Front_Left_Motor->Set(speed - turn);
	Front_Right_Motor->Set(speed + turn);
	Middle_Left_Motor->Set(speed - turn);
	Middle_Right_Motor->Set(speed + turn);
	Back_Left_Motor->Set(speed - turn);
	Back_Right_Motor->Set(speed + turn);
}

void DriveSub::Shift(DoubleSolenoid::Value value)
{
	Gear_Box->Set(value);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
