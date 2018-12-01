#include "BallPickUpCMD.h"

BallPickUpCMD::BallPickUpCMD(){
	Requires(CommandBase::BallPickUpSubsystem.get());

	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void BallPickUpCMD::Initialize() {
	CommandBase::BallPickUpSubsystem->SetSpeed(0);

}

// Called repeatedly when this Command is scheduled to run
void BallPickUpCMD::Execute()
{
	if(CommandBase::oi->GetButton(1, Buttons::B))
	{
		CommandBase::BallPickUpSubsystem->SetSpeed(1);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool BallPickUpCMD::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void BallPickUpCMD::End() {
	CommandBase::BallPickUpSubsystem->SetSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BallPickUpCMD::Interrupted() {

}
