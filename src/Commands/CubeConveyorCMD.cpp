#include "CubeConveyorCMD.h"
#include <iostream>

CubeConveyorCMD::CubeConveyorCMD()
{
	Requires(CommandBase::CubeConveyorSubsystem.get());
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
	if(CommandBase::oi->GetButton(1, Buttons::Start))
	{
		CommandBase::CubeConveyorSubsystem->SetSoldenoid(DoubleSolenoid::Value::kForward);
	}
	else
	{
		CommandBase::CubeConveyorSubsystem->SetSoldenoid(DoubleSolenoid::Value::kReverse);
	}

	/*
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
	*/

	if(CommandBase::oi->GetButton(1, Buttons::X))
	{
		CommandBase::CubeConveyorSubsystem->SetHopper(.5);
	}
	else
	{
		CommandBase::CubeConveyorSubsystem->SetHopper(0);
	}
	if (CommandBase::CubeConveyorSubsystem->GetSwitch())
	{
		if (!a)
		{
			CommandBase::oi->in_cube_ball_count++;
		}
		a = true;
	}
	else
	{
		a = false;
	}
	SmartDashboard::PutNumber("IN CUBE", CommandBase::oi->in_cube_ball_count);
	if(CommandBase::oi->GetAxis(1, Axis::RightTrigger) > .01)
	{
		if(!CommandBase::CubeConveyorSubsystem->GetFrontSwitch())
		{
			CommandBase::CubeConveyorSubsystem->SetFront(1);
		}
		else
		{
			CommandBase::CubeConveyorSubsystem->SetFront(0);
		}
	}
	else
	{
		if(false)//CommandBase::oi->in_cube_ball_count < CommandBase::oi->ball_threshold)
		{
			CommandBase::CubeConveyorSubsystem->SetFront(0);
		}
		else
		{
			if(!CommandBase::CubeConveyorSubsystem->GetBackSwitch() && CommandBase::CubeConveyorSubsystem->GetFrontSwitch())
			{
				CommandBase::CubeConveyorSubsystem->SetFront(1);
				CommandBase::CubeConveyorSubsystem->SetBack(.45);
			}
			else
			{
				if(CommandBase::oi->GetButton(1, Buttons::B))
				{
					CommandBase::CubeConveyorSubsystem->SetBack(.5);
					CommandBase::CubeConveyorSubsystem->SetFront(1);
				}
				else
				{
					CommandBase::CubeConveyorSubsystem->SetBack(0);
					CommandBase::CubeConveyorSubsystem->SetFront(0);
				}
			}
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool CubeConveyorCMD::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void CubeConveyorCMD::End()
{
	CommandBase::CubeConveyorSubsystem->SetFront(0);
	CommandBase::CubeConveyorSubsystem->SetBack(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CubeConveyorCMD::Interrupted()
{

}
