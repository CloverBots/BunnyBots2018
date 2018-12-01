#include "CubePickUpCMD.h"

CubePickUpCMD::CubePickUpCMD(){
	Requires(CommandBase::CubePickUpSubsystem.get());
	Requires(CommandBase::BallPickUpSubsystem.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void CubePickUpCMD::Initialize() {
	CommandBase::CubePickUpSubsystem->SetSpeed(0);
}

// Called repeatedly when this Command is scheduled to run
void CubePickUpCMD::Execute() {
	if(CommandBase::oi->GetButton(1, Buttons::A))
	{
		CommandBase::CubePickUpSubsystem->SetSpeed(1);
		CommandBase::BallPickUpSubsystem->SetSpeed(1);
	}
	else
	{
		CommandBase::CubePickUpSubsystem->SetSpeed(0);
		CommandBase::BallPickUpSubsystem->SetSpeed(0);
	}
	if(CommandBase::oi->GetButton(1, Buttons::X))
	{
		CommandBase::CubePickUpSubsystem->Grab(DoubleSolenoid::Value::kForward);
	}
	else
	{
		CommandBase::CubePickUpSubsystem->Grab(DoubleSolenoid::Value::kForward);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool CubePickUpCMD::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CubePickUpCMD::End() {
	CommandBase::CubePickUpSubsystem->SetSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CubePickUpCMD::Interrupted() {

}
