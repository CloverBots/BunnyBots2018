#include "BallPickUpCMD.h"
#include <iostream>

BallPickUpCMD::BallPickUpCMD()
{
	Requires(CommandBase::BallPickUpSubsystem.get());

	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void BallPickUpCMD::Initialize()
{
	//CommandBase::BallPickUpSubsystem->SetSpeed(0);
}

// Called repeatedly when this Command is scheduled to run
void BallPickUpCMD::Execute()
{
	if(CommandBase::oi->GetAxis(1, Axis::RightTrigger) > .01)
	{
		std::cout << "?" << std::endl;
		CommandBase::BallPickUpSubsystem->SetSpeed(-.75);
	}
	else if(CommandBase::oi->GetAxis(1, Axis::LeftTrigger) > .1)
	{
		CommandBase::BallPickUpSubsystem->SetSpeed(-.5);
	}
	else
	{
		CommandBase::BallPickUpSubsystem->SetSpeed(0);

	}
}

// Make this return true when this Command no longer needs to run execute()
bool BallPickUpCMD::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void BallPickUpCMD::End()
{
	CommandBase::BallPickUpSubsystem->SetSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BallPickUpCMD::Interrupted()
{

}
