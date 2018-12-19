/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "CubeConveyorAutoCMD.h"

#include <iostream>

CubeConveyorAutoCMD::CubeConveyorAutoCMD()
{
	Requires(CommandBase::CubeConveyorSubsystem.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void CubeConveyorAutoCMD::Initialize()
{
	CommandBase::oi->in_cube_ball_count = 0;
}

// Called repeatedly when this Command is scheduled to run
void CubeConveyorAutoCMD::Execute()
{
	if(CommandBase::CubeConveyorSubsystem->GetFrontSwitch())
	{
		CommandBase::oi->in_zone_1 = true;
	}
	else
	{
		CommandBase::oi->in_zone_1 = false;
	}
	if(!CommandBase::CubeConveyorSubsystem->GetFrontSwitch())
	{
		CommandBase::CubeConveyorSubsystem->SetFront(1);
	}
	else
	{
		if(CommandBase::oi->in_cube_ball_count == 0)
		{
			//CommandBase::oi->in_cube_ball_count = 0;
			CommandBase::CubeConveyorSubsystem->SetHopper(1);
			CommandBase::CubeConveyorSubsystem->SetFront(0);
		}
		else
		{
			CommandBase::CubeConveyorSubsystem->SetHopper(0);
			CommandBase::CubeConveyorSubsystem->SetFront(1);
			CommandBase::CubeConveyorSubsystem->SetBack(.5);
		}
	}
	if(CommandBase::oi->throw_latch)
	{
		if(CommandBase::CubeConveyorSubsystem->GetFrontSwitch())
		{
			CommandBase::oi->throw_latch = false;
		}
	}
	SmartDashboard::PutNumber("IN CUBE", CommandBase::oi->in_cube_ball_count);
	if (CommandBase::CubeConveyorSubsystem->GetSwitch())
	{
		if (!latch1)
		{
			CommandBase::oi->in_cube_ball_count++;
		}
		latch1 = true;
	}
	else
	{
		latch1 = false;
	}
	if(CommandBase::CubeConveyorSubsystem->GetBackSwitch())
	{
		if(!latch2)
		{
			start_time = clock();
			latch2 = true;
		}
	}
	if(CommandBase::oi->throw_cube)
	{
		std::cout << "THROW" << std::endl;
		CommandBase::CubeConveyorSubsystem->SetFront(1);
		CommandBase::CubeConveyorSubsystem->SetBack(.5);
	}
	if(!CommandBase::CubeConveyorSubsystem->GetFrontSwitch() && !CommandBase::CubeConveyorSubsystem->GetFrontSwitch())
	{
		CommandBase::oi->throw_cube = false;
	}
	if(start_time != 0)
	{
		end_time = clock();
		if((double)(end_time - start_time)/CLOCKS_PER_SEC >= .05)
		{
			start_time = 0;
			latch1 = false;
			latch2 = false;
			CommandBase::oi->reset = true;
			CommandBase::oi->in_cube_ball_count = 0;
		}
	}
}
//the kek is a lie
// Make this return true when this Command no longer needs to run execute()
bool CubeConveyorAutoCMD::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void CubeConveyorAutoCMD::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CubeConveyorAutoCMD::Interrupted()
{

}
