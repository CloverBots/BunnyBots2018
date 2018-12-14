#include "BallConveyorCMD.h"

BallConveyorCMD::BallConveyorCMD()
{
	start_time = 0;
	Requires(CommandBase::BallConveyorSubsystem.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void BallConveyorCMD::Initialize()
{
	CommandBase::BallConveyorSubsystem->SetSpeed(0);
}

// Called repeatedly when this Command is scheduled to run
void BallConveyorCMD::Execute()
{
	if(CommandBase::oi->GetAxis(1, Axis::LeftTrigger))
	{
		CommandBase::BallConveyorSubsystem->SetSpeed(.45);
	}
	else if(CommandBase::oi->GetAxis(1, Axis::RightTrigger))
	{
		CommandBase::BallConveyorSubsystem->SetSpeed(.45);
	}
	else
	{
		CommandBase::BallConveyorSubsystem->SetSpeed(0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool BallConveyorCMD::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void BallConveyorCMD::End()
{
	CommandBase::BallConveyorSubsystem->SetSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BallConveyorCMD::Interrupted()
{

}
