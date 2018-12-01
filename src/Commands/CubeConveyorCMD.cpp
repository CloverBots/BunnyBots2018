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
	CommandBase::CubeConveyorSubsystem->SetServo(CommandBase::oi->GetAxis(1, Axis::RightTrigger) * 360);
	switch(CommandBase::oi->GetDPad(1))
	{
	case(0):
		CommandBase::oi->ball_threshold = 8;
		break;
	case(90):
		CommandBase::oi->ball_threshold = 6;
		break;
	case(270):
		CommandBase::oi->ball_threshold = 4;
		break;
	case(180):
		CommandBase::oi->ball_threshold = 2;
		break;
	}
	if(CommandBase::CubeConveyorSubsystem->GetFrontSwitch())
	{
		if(CommandBase::oi->in_cube_ball_count < CommandBase::oi->ball_threshold)
		{
			CommandBase::CubeConveyorSubsystem->SetEnabled(true);
			CommandBase::CubeConveyorSubsystem->SetSetPoint(CommandBase::CubeConveyorSubsystem->GetSetPoint() + 5461);
		}
		else
		{
			CommandBase::CubeConveyorSubsystem->SetEnabled(false);
			if(!CommandBase::CubeConveyorSubsystem->GetBackSwitch())
			{
				CommandBase::CubeConveyorSubsystem->SetFront(1);
			}
		}
	}
	if(CommandBase::oi->GetButton(1, Buttons::Y) && CommandBase::CubeConveyorSubsystem->GetBackSwitch())
	{
		CommandBase::CubeConveyorSubsystem->SetBack(1);
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
