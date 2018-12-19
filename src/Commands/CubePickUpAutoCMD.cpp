/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "CubePickUpAutoCMD.h"
#include <iostream>
#include <chrono>

CubePickUpAutoCMD::CubePickUpAutoCMD(bool grab, double ball, double cube) : grab(grab), ball(ball), cube(cube)
{
	Requires(CommandBase::CubePickUpSubsystem.get());
	Requires(CommandBase::BallPickUpSubsystem.get());
	start = 0;
	end = 0;
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void CubePickUpAutoCMD::Initialize()
{
	CommandBase::CubePickUpSubsystem->Grab(DoubleSolenoid::Value::kReverse);
}

// Called repeatedly when this Command is scheduled to run
void CubePickUpAutoCMD::Execute()
{
	if(CommandBase::CubePickUpSubsystem->GetSensor())
	{
		if(!CommandBase::oi->throw_latch)
		{
			if(CommandBase::oi->in_zone_1)
			{
				CommandBase::oi->throw_latch = true;
				CommandBase::oi->reset = true;
				CommandBase::oi->throw_cube = true;
			}
		}
		if(!latch2)
		{
			latch2 = true;
			start_time = std::chrono::high_resolution_clock::now();
			start = 1;
		}
	}
	if(start != 0)
	{
		end_time = std::chrono::high_resolution_clock::now();
		end = 1;
		//if((double)(end_time - start_time)/CLOCKS_PER_SEC >= 0)
		//{
			if(!latch)
			{
				CommandBase::CubePickUpSubsystem->Grab(DoubleSolenoid::Value::kForward);
			}
			latch = true;
		//}
		if(start != 0)
		{
			end_time = std::chrono::high_resolution_clock::now();
			end = 1;
			if(std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() >= .7)
			{
				latch = true;
				std::cout << "GRAB" << std::endl;
				CommandBase::CubePickUpSubsystem->Grab(DoubleSolenoid::Value::kReverse);
			}
		}
	}
	/*
	else
	{
		if(!latch)
		CommandBase::CubePickUpSubsystem->Grab(DoubleSolenoid::Value::kReverse);
	}
	*/

	CommandBase::BallPickUpSubsystem->SetSpeed(ball);
	CommandBase::CubePickUpSubsystem->SetSpeed(cube);

	if(CommandBase::oi->reset)
	{
		CommandBase::oi->reset = false;
		latch = false;
		start = 0;
		latch2 = false;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool CubePickUpAutoCMD::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void CubePickUpAutoCMD::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CubePickUpAutoCMD::Interrupted()
{

}

