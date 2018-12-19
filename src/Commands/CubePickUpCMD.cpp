#include "CubePickUpCMD.h"
#include <iostream>

CubePickUpCMD::CubePickUpCMD()
{
	Requires(CommandBase::CubePickUpSubsystem.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void CubePickUpCMD::Initialize()
{
	CommandBase::CubePickUpSubsystem->SetSpeed(0);
}

// Called repeatedly when this Command is scheduled to run
void CubePickUpCMD::Execute()
{
	if(CommandBase::CubePickUpSubsystem->GetSensor())
	{
		std::cout << "HIT" << std::endl;
	}
	CommandBase::CubePickUpSubsystem->SetSpeed(CommandBase::oi->GetAxis(1, Axis::RightTrigger));
	if(CommandBase::oi->GetButton(1, Buttons::A))
	{
		CommandBase::CubePickUpSubsystem->Grab(DoubleSolenoid::Value::kForward);
	}
	else
	{
		CommandBase::CubePickUpSubsystem->Grab(DoubleSolenoid::Value::kReverse);
	}

}

// Make this return true when this Command no longer needs to run execute()
bool CubePickUpCMD::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void CubePickUpCMD::End()
{
	CommandBase::CubePickUpSubsystem->SetSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CubePickUpCMD::Interrupted()
{

}
