#include "DriveCMD.h"
#include "WPILib.h"
#include "../CommandBase.h"
#include "DriveCMD.h"

DriveCMD::DriveCMD() {
	Requires(CommandBase::driveSubsystem.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void DriveCMD::Initialize()
{
	CommandBase::driveSubsystem->Drive(0,00);
	CommandBase::driveSubsystem->Shift(DoubleSolenoid::Value::kForward);
}

// Called repeatedly when this Command is scheduled to run
void DriveCMD::Execute()
{
		CommandBase::driveSubsystem->Drive(CommandBase::oi->GetAxis(0, Axis::RightUpDown), CommandBase::oi->GetAxis(0, Axis::LeftLeftRight));
		if(CommandBase::oi->GetButton(0, Buttons::A))
		{
			CommandBase::driveSubsystem->Shift(DoubleSolenoid::Value::kForward);
		}
		if(CommandBase::oi->GetButton(0, Buttons::B))
		{
			CommandBase::driveSubsystem->Shift(DoubleSolenoid::Value::kReverse);
		}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveCMD::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveCMD::End()
{
	CommandBase::driveSubsystem->Drive(0,0);
	CommandBase::driveSubsystem->Shift(DoubleSolenoid::Value::kOff);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveCMD::Interrupted() {

}
