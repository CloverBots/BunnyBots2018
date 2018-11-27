#include "CubeConveyorCMD.h"

CubeConveyorCMD::CubeConveyorCMD(){
	Requires(CommandBase::CubeConveyorSubsystem.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void CubeConveyorCMD::Initialize()
{
	CommandBase::CubeConveyorSubsystem->SetFront(0);
	CommandBase::CubeConveyorSubsystem->SetBack(0);
}

// Called repeatedly when this Command is scheduled to run
void CubeConveyorCMD::Execute()
{
	if(CommandBase::oi->GetButton(1, Buttons::A))
	{
		if(!CommandBase::CubeConveyorSubsystem->GetFrontSwitch())
		{
			CommandBase::CubeConveyorSubsystem->SetFront(1);
		}
	}
	if(CommandBase::CubeConveyorSubsystem->GetFrontSwitch() && CommandBase::CubeConveyorSubsystem->GetBackSwitch())
	{
		if(CommandBase::CubeConveyorSubsystem->GetFrontSwitch())
		{
			CommandBase::CubeConveyorSubsystem->SetFront(1);
		}
		if(!CommandBase::CubeConveyorSubsystem->GetBackSwitch())
		{
			CommandBase::CubeConveyorSubsystem->SetBack(1);
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool CubeConveyorCMD::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void CubeConveyorCMD::End() {
	CommandBase::CubeConveyorSubsystem->SetFront(0);
	CommandBase::CubeConveyorSubsystem->SetBack(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CubeConveyorCMD::Interrupted() {

}
